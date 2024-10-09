using Microsoft.AspNetCore.Identity;
using Microsoft.AspNetCore.Mvc;
using MoneySIDE.Models; // Certifique-se de incluir o namespace do seu modelo
using CodeData.Services;
using System.Collections.Generic;
using System.Security.Claims;
using MoneySIDE.Services;
using Microsoft.AspNetCore.Authorization;

[Authorize]
public class AnaliseController : Controller
{
    private readonly ComprovanteService _comprovanteService;

    public AnaliseController(ComprovanteService comprovanteService)
    {
        _comprovanteService = comprovanteService;
    }

    [HttpGet]
    public IActionResult Index(string filePath)
    {
        var userId = User.FindFirstValue(ClaimTypes.NameIdentifier);
        List<Comprovante> comprovantes = _comprovanteService.GetComprovantes(userId);

        if (comprovantes == null || !comprovantes.Any())
        {
            ModelState.AddModelError("", "Nenhum comprovante encontrado.");
            ViewBag.Analises = new List<Analise>();
        }
        else
        {
            var analises = comprovantes.Select(c =>
            {
                decimal valorDecimal;
                decimal.TryParse(c.Valor, out valorDecimal);

                return new Analise
                {
                    Remetente = c.NomeRemetente,
                    Destinatario = c.NomeDestinatario,
                    Data = (DateTime)c.DataCadastro,
                    Valor = valorDecimal
                };
            }).ToList();

            ViewBag.Analises = analises;

            // Criar dados para o novo gráfico
            var valoresPorData = analises
                .GroupBy(a => a.Data.Date)
                .Select(g => new
                {
                    Data = g.Key,
                    SomaValores = g.Sum(a => a.Valor)
                }).ToList();

            ViewBag.ValoresPorData = valoresPorData;
        }

        ViewBag.FilePath = filePath;
        return View();
    }


    [HttpPost]
    public IActionResult GenerateChart(Analise chartModel)
    {
        var userId = User.FindFirstValue(ClaimTypes.NameIdentifier);
        List<Comprovante> comprovantes = _comprovanteService.GetComprovantes(userId);

        if (comprovantes == null || !comprovantes.Any())
        {
            ModelState.AddModelError("", "Nenhum comprovante encontrado.");
            return View(chartModel); // Retorna a mesma visão com erro
        }

        var memoryStream = chartModel.GenerateExcelChart(comprovantes);
        string fileName = $"Relatorio_{userId}_{DateTime.Now:yyyyMMddHHmmss}.xlsx";
        return File(memoryStream, "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet", fileName);
    }
}