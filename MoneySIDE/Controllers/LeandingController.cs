using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using MoneySIDE.Models;

namespace MoneySIDE.Controllers
{
    public class LeandingController: Controller
    {
        private readonly ILogger<HomeController> _logger;

        public LeandingController(ILogger<HomeController> logger)
        {
            _logger = logger;
        }

        public IActionResult Index()
        {
            return View();
        }

        public IActionResult Privacy()
        {
            return View();
        }
    }
}
