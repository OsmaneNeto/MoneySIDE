using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using MoneySIDE.Areas.Identity.Data;
using MoneySIDE.Models;

public class ComprovanteController : Controller
{
    private readonly ApplicationDbContext _context;

    public ComprovanteController(ApplicationDbContext context)
    {
        _context = context;
    }

    // Action para buscar o comprovante por ID
    [HttpGet]
    public JsonResult GetById(int id)
    {
        var comprovante = _context.Comprovantes.Find(id);
        return Json(comprovante);
    }

    // Action para atualizar o comprovante
    //[HttpPost]
    //public async Task<IActionResult> Update(Comprovante comprovante)
    //{
    //    if (ModelState.IsValid)
    //    {
    //        _context.Update(comprovante);
    //        await _context.SaveChangesAsync();
    //        return Ok();
    //    }
    //    return BadRequest();
    //}

    [HttpPost]
    
    public IActionResult Update(Comprovante model)
    {
        Console.WriteLine("Model: " + model.DataCadastro);

        if (ModelState.IsValid)
        {
            Console.WriteLine("Entrou no codicional if");
            try
            {
                var comprovante = _context.Comprovantes.Find(model.Id);

                if (comprovante == null)
                {
                    return NotFound();
                }

                // Atualizar os campos necessários
                comprovante.Valor = model.Valor;
                comprovante.NomeRemetente = model.NomeRemetente;
                comprovante.NomeBanco = model.NomeBanco;
                comprovante.TipoComprovante = model.TipoComprovante;

                // Salvar as alterações
                _context.SaveChanges();

                return Ok();
            }
            catch (Exception ex)
            {
                return BadRequest($"Erro ao atualizar: {ex.Message}");
            }
        }

        return BadRequest("Dados inválidos");
    }

    // Action para deletar o comprovante
    [HttpPost]
    public async Task<IActionResult> Delete(int id)
    {
        var comprovante = await _context.Comprovantes.FindAsync(id);
        if (comprovante != null)
        {
            _context.Comprovantes.Remove(comprovante);
            await _context.SaveChangesAsync();
            return Ok();
        }
        return NotFound();
    }
}
