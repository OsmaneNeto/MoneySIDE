using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using MoneySIDE.Areas.Identity.Data;

namespace MoneySIDE.Controllers
{
    public class ComprovanteController : Controller
    {
        private readonly ApplicationDbContext _context;

        public ComprovanteController(ApplicationDbContext context)
        {
            _context = context;
        }

        public IActionResult Index()
        {
            return View();
        }

        [HttpGet]
        public async Task<IActionResult> GetComprovantes()
        {
            var comprovantes = await _context.Comprovantes
                .Select(c => new
                {
                    Id = c.Id,
                    Valor = string.IsNullOrEmpty(c.Valor) ? "não encontrado" : c.Valor,
                    NomeRemetente = string.IsNullOrEmpty(c.NomeRemetente) ? "não encontrado" : c.NomeRemetente,
                    NomeBanco = string.IsNullOrEmpty(c.NomeBanco) ? "não encontrado" : c.NomeBanco,
                    TipoComprovante = string.IsNullOrEmpty(c.TipoComprovante) ? "não encontrado" : c.TipoComprovante,
                    DataCadastro = c.DataCadastro == default ? "não encontrado" : c.DataCadastro.ToString("yyyy-MM-dd HH:mm:ss"), // Format for DataTables
                    UserId = string.IsNullOrEmpty(c.UserId) ? "não encontrado" : c.UserId
                })
                .ToListAsync();

            return Json(new { data = comprovantes });
        }
    }
}
