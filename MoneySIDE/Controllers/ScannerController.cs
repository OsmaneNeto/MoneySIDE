using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Http;
using System;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using iText.Kernel.Pdf;
using iText.Kernel.Pdf.Canvas.Parser;
using iText.Kernel.Pdf.Canvas.Parser.Listener;
using Microsoft.AspNetCore.Authorization;
using System.Collections.Generic;
using Tesseract; // Biblioteca OCR
using SixLabors.ImageSharp; // Biblioteca para manipulação de imagens
using SixLabors.ImageSharp.PixelFormats;
using SixLabors.ImageSharp.Processing;
using SixLabors.ImageSharp.PixelFormats;
using SixLabors.ImageSharp.Formats.Bmp;
using SixLabors.ImageSharp.Formats.Pbm;

namespace MoneySIDE.Controllers
{
    [Authorize]
    public class ScannerController : Controller
    {
        private readonly IWebHostEnvironment _hostingEnvironment;

        public ScannerController(IWebHostEnvironment hostingEnvironment)
        {
            _hostingEnvironment = hostingEnvironment;
        }

        // GET: BankStatement
        public IActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Upload(IFormFile file)
        {
            if (file != null && file.Length > 0)
            {
                try
                {
                    // Diretório de uploads
                    string uploadsDir = Path.Combine(_hostingEnvironment.WebRootPath, "uploads");
                    string filePath = Path.Combine(uploadsDir, file.FileName);

                    // Criação do diretório se não existir
                    if (!Directory.Exists(uploadsDir))
                    {
                        Directory.CreateDirectory(uploadsDir);
                    }

                    // Salvar o arquivo no diretório de uploads
                    using (var stream = new FileStream(filePath, FileMode.Create))
                    {
                        file.CopyTo(stream);
                    }

                    // Extrair texto do arquivo conforme o tipo
                    string extractedText = ExtractTextFromImage(filePath);

                    string fileExtension = Path.GetExtension(filePath).ToLower();
                    if (fileExtension == ".pdf")
                    {
                        extractedText = ExtractTextFromPdf(filePath);
                    }
                    else if (fileExtension == ".jpg" || fileExtension == ".png")
                    {
                        extractedText = ExtractTextFromImage(filePath);
                    }
                    else
                    {
                        ViewBag.Result = "Tipo de arquivo não suportado.";
                        return View("Index");
                    }

                    // Identificar o tipo de comprovante
                    string comprovanteTipo = IdentificarTipoComprovante(extractedText);

                    // Encontrar valores monetários
                    ViewBag.ExtractedText = extractedText; // Adicione esta linha para depuração
                    string monetaryValues = FindMonetaryValues(extractedText);

                    string pattern = @"Valor:\s*R\$(\d+,\d{2})";

                    ViewBag.Result = $"Tipo de Comprovante: {comprovanteTipo}<br>Valores Monetários: {monetaryValues}";
                }
                catch (Exception e)
                {
                    ViewBag.Result = "Erro ao processar o arquivo: " + e.Message;
                }
            }
            else
            {
                ViewBag.Result = "Nenhum arquivo selecionado.";
            }

            return View("Index");
        }

        private string ExtractTextFromPdf(string filePath)
        {
            StringBuilder text = new StringBuilder();

            using (PdfReader reader = new PdfReader(filePath))
            {
                using (PdfDocument pdfDoc = new PdfDocument(reader))
                {
                    var numberOfPages = pdfDoc.GetNumberOfPages();

                    for (int i = 1; i <= numberOfPages; i++)
                    {
                        var page = pdfDoc.GetPage(i);
                        var strategy = new SimpleTextExtractionStrategy();
                        var pageText = PdfTextExtractor.GetTextFromPage(page, strategy);
                        text.Append(pageText);
                    }
                }
            }

            return text.ToString();
        }

        private string ExtractTextFromImage(string filePath)
        {
            StringBuilder text = new StringBuilder();

            try
            {
                // Caminho para o diretório tessdata
                string tessdataPath = Path.Combine(_hostingEnvironment.WebRootPath, "tessdata");

                if (!Directory.Exists(tessdataPath))
                {
                    return "Diretório tessdata não encontrado.";
                }

                // Crie um arquivo temporário para armazenar a imagem
                string tempFilePath = Path.GetTempFileName() + ".bmp";

                using (var image = Image.Load<Rgba32>(filePath))
                {
                    image.Mutate(x => x
                        .Grayscale() // Converter para escala de cinza
                        .Contrast(1.5f)); // Aumentar o contraste

                    // Salvar a imagem temporária no formato BMP
                    using (var stream = new FileStream(tempFilePath, FileMode.Create))
                    {
                        image.Save(stream, new BmpEncoder());
                    }
                }

                // Processar o arquivo BMP com o Tesseract
                using (var engine = new TesseractEngine(tessdataPath, "eng", EngineMode.Default))
                {
                    using (var pix = Pix.LoadFromFile(tempFilePath))
                    {
                        using (var page = engine.Process(pix))
                        {
                            text.Append(page.GetText());
                        }
                    }
                }

                // Remover o arquivo temporário
                System.IO.File.Delete(tempFilePath);
            }
            catch (Exception ex)
            {
                return "Erro ao processar imagem: " + ex.Message;
            }

            return text.ToString();
        }



        private string IdentificarTipoComprovante(string texto)
        {
            var tipos = new Dictionary<string, string>
            {
                { "TED", @"\b(TED|Transferência Eletrônica Disponível)\b" },
                { "DOC", @"\b(DOC|Documento de Ordem de Crédito)\b" },
                { "PIX", @"\bPIX\b" },
                { "PayPal", @"\bPayPal\b" },
                { "Skrill", @"\bSkrill\b" },
                { "Neteller", @"\bNeteller\b" },
                { "Apple Pay", @"\bApple Pay\b" },
                { "Google Pay", @"\bGoogle Pay\b" },
                { "Samsung Pay", @"\bSamsung Pay\b" },
                { "Débito", @"\bDébito\b" },
                { "Crédito", @"\bCrédito\b" },
                { "Dinheiro", @"\bDinheiro\b" },
                { "Bitcoin", @"\bBitcoin\b" },
                { "Ethereum", @"\bEthereum\b" },
                { "WhatsApp Pay", @"\bWhatsApp Pay\b" },
                { "Facebook Pay", @"\bFacebook Pay\b" },
                { "Cheque", @"\bCheque\b" }
            };

            foreach (var tipo in tipos)
            {
                if (Regex.IsMatch(texto, tipo.Value, RegexOptions.IgnoreCase))
                {
                    return tipo.Key;
                }
            }

            return "Desconhecido";
        }

        private string FindMonetaryValues(string text)
        {
            if (string.IsNullOrEmpty(text))
            {
                return "Nenhum texto extraído.";
            }

            // Expressão regular mais genérica para valores monetários
            string pattern = @"R\$\s*(\d+,\d{2})";
            var matches = Regex.Matches(text, pattern);

            if (matches.Count > 0)
            {
                // Retorna todos os valores encontrados separados por vírgula
                var values = string.Join(", ", matches.Cast<Match>().Select(m => m.Groups[1].Value));
                return values;
            }
            else
            {
                return "Nenhum valor monetário encontrado.";
            }
        }

    }
}
