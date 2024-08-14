using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using MoneySIDE.Data;
using MoneySIDE.Models;

namespace MoneySIDE.Controllers
{
    public class UsuariosController : Controller
        //UsuariosController é uma classe que herda de Controller e
        //é responsável por lidar com as requisições HTTP relacionadas a usuários.
    {
        private readonly ApplicationContext _context;//interage om o banco de dados

        //construtor
        public UsuariosController(ApplicationContext context)
        {

            _context = context;
        }

        //Injeção de dependência: O construtor recebe uma instância do Contexto e a atribui à propriedade _context.
        //Isso permite que o controlador utilize o contexto para acessar o banco de dados

        // GET: Usuarios
        //Retorna o Index.cshtml
        public async Task<IActionResult> Index()
        {

            return View();
        }



        // GET: Usuarios/Details/5
        public async Task<IActionResult> Details(int? idUsuario)
            //Recebe um paramêtro id e procura o usuário pelo id especificado
        {
            //caso o id seja encontrado ele retorna o usuário como um modelo 
            //caso o id não seja encontrado ele retorna um não encontrado 
            if (idUsuario == null)
            {
                return NotFound();
            }

            var usuario = await _context.Usuarios
                .FirstOrDefaultAsync(m => m.IdUsuario == idUsuario);
            if (usuario == null)
            {
                return NotFound();
            }

            return View(usuario);
        }

        // GET: Usuarios/Create
        //cadastra um novo usuário
        public IActionResult Register()
        {
            return View();
        }


        // POST: Usuarios/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        //Recebe um objeto usuário para registrar os dados do novo usuário
        public async Task<IActionResult> Register([Bind("IdUsuario,Nome,Senha,Email, Login")] Usuario usuario)
        {
            if (ModelState.IsValid)//Valida os dados antes e entrar no banco
            {
                _context.Add(usuario);//adiciona o usuário ao banco de dados
                await _context.SaveChangesAsync(); //salva as alterações
                return RedirectToAction(nameof(Index));//quando bem sucedido redireciona para a página inicial
            }
            return View(usuario);
           //Se a validação falhar, retorna a view Register.cshtml novamente,
           //passando o objeto usuario para exibir os erros de validação.
        }

        // GET: Usuarios/Create
        public IActionResult Login()
        {
            return View();
        }

        // POST: Usuarios/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Login(string email, string senha)//recebe os paramêtros
        {



            //Busca o usuário pelo email dentro do banco de dados
            var user = await _context.Usuarios.FirstOrDefaultAsync(m => m.Email == email);

            //Caso não seja encontrado ele retornará not found
            if (user == null)
            {

                return NotFound();

            }

            //Caso encontre ele irá comparar a senha inserida pela registrada
            if (user.Senha == senha)
            {
                //caso a senha seja aprovada será armazenado os dados de id, email e senha na sessão,
                //isso se deve aoHttpContext.Session
                HttpContext.Session.SetInt32("IdUsuario", user.IdUsuario);
                HttpContext.Session.SetString("username", user.Nome);
                HttpContext.Session.SetString("email", user.Email);

                ViewData["login"] = user.IdUsuario.ToString();//Indicará que o usuário está logado


                return View("Index", user);// Ao fim do processo ele redirecionará para a página inicial.
            }



            return View(user);//Se o processo falhar ele será redirecionado para o login
        }


    
        //public async Task<IActionResult> Index()
        //{
        //    View();
        //}


        // GET: Usuarios/Edit/5
        //Edita as informações do usuário
        public async Task<IActionResult> Edit(int? idUsuario)//recebe o paramêtro Id
        {
            //Tratamento caso o valor seja nulo
            if (idUsuario == null)
            {
                return NotFound();
            }
            //Tratamento caso o usuário não seja encontrado no banco de dados
            var usuario = await _context.Usuarios.FindAsync(idUsuario);//procura o usuário pelo id
            if (usuario == null)//se não encontra o usuário retorna not found
            {
                return NotFound();
            }
            return View(usuario);//passa o usuário como modelo de edição.
        }

        // POST: Usuarios/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int idUsuario, [Bind("IdUsuario,Nome,Senha,Email, Login")] Usuario usuario)//recebe o id do usuário e um objetousuário
        {
            if (idUsuario != usuario.IdUsuario)//verifica se ambos os id correspondem
            {
                return NotFound();
            }

            if (ModelState.IsValid)//valida os dados antes de atualizar
            {
                try//Se a validação for bem sucedida tenta atualizar o usuário
                {
                    _context.Update(usuario);//atualiza
                    await _context.SaveChangesAsync();//salva as alterações
                }
                catch (DbUpdateConcurrencyException)
                //Trata a exceção DbUpdateConcurrencyException
                //que pode ocorrer em cenários de concorrência de dados.
                {
                    if (!UsuarioExists(usuario.IdUsuario))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }
                return RedirectToAction(nameof(Index));//se bem sucedido ele redireciona
            }
            return View(usuario);//se falhar ele retorna para a edição com o usuário para retornar os erros
        }

        // GET: Usuarios/Delete/5
        public async Task<IActionResult> Delete(int? idUsuario)
        {
            //valida o valor null
            if (idUsuario == null)
            {
                return NotFound();
            }
            //valida o usuário pelo id
            var usuario = await _context.Usuarios
                .FirstOrDefaultAsync(m => m.IdUsuario == idUsuario);
            if (usuario == null)//se não encontrar retorna not found
            {
                return NotFound();
            }

            return View(usuario);//se encontrado passa o usuário para confirmar a exclusão.
        }

        // POST: Usuarios/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int idUsuario)//recebe o id de um usuário
        {
            var usuario = await _context.Usuarios.FindAsync(idUsuario); ; //procura o usuário
            if (usuario != null)//caso seja encontrado algum usuário ele irá
            {
                _context.Usuarios.Remove(usuario);//excluir o usuário em questão
            }

            await _context.SaveChangesAsync();//salva as alterações feitas
            return RedirectToAction(nameof(Index));//redireciona
        }

        private bool UsuarioExists(int idUsuario)
        {
            return _context.Usuarios.Any(e => e.IdUsuario == idUsuario);
        }
    }
}
