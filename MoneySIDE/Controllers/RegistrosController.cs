using Microsoft.EntityFrameworkCore;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Identity;
using System.Linq;
using System.Threading.Tasks;
using MoneySIDE.Areas.Identity.Data;
using Microsoft.AspNetCore.Authorization;

namespace MoneySIDE.Controllers
{
    public class RegistrosController : Controller
    {
        private readonly ApplicationDbContext _context; // DbContext para acesso ao banco de dados
        private readonly UserManager<IdentityUser> _userManager;

        public RegistrosController(ApplicationDbContext context, UserManager<IdentityUser> userManager)
        {
            _context = context;
            _userManager = userManager;
        }

        [Authorize]
        public async Task<IActionResult> Index()
        {
            var userId = _userManager.GetUserId(User); // Obtém o ID do usuário logado
            var comprovantes = await _context.Comprovantes
                .Where(c => c.UserId == userId)
                .ToListAsync(); // Obtém os comprovantes do usuário logado

            return View(comprovantes);
        }
    }
}