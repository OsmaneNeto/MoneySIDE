using Microsoft.AspNetCore.Mvc;

namespace MoneySIDE.Controllers
{
    public class UsuariosController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }
    }
}
