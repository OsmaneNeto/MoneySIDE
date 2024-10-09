using MoneySIDE.Models;
using Microsoft.EntityFrameworkCore;
using System.Collections.Generic;
using System.Linq;
using MoneySIDE.Areas.Identity.Data;
using MoneySIDE.Services; 

namespace MoneySIDE.Services
{
    public class ComprovanteService
    {
        private readonly ApplicationDbContext _context;

        public ComprovanteService(ApplicationDbContext context)
        {
            _context = context;
        }

        public List<Comprovante> GetComprovantes(string userId)
        {
            return _context.Comprovantes.Where(c => c.UserId == userId).ToList();
        }
    }
}
