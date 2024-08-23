using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Hosting;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System;
using System.IO;

using System.Text.RegularExpressions;

using Leadtools;
using Leadtools.Ocr;
using Leadtools.Codecs;
using Leadtools.Ocr.LEADEngine;
using iTextSharp.text.pdf;
using Microsoft.AspNetCore.Authorization;

namespace MoneySIDE.Controllers
{
    [Authorize]
    public class ScannerController: Controller
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
                    string uploadsDir = Path.Combine(_hostingEnvironment.WebRootPath, "uploads");
                    string filePath = Path.Combine(uploadsDir, file.FileName);

                    if (!Directory.Exists(uploadsDir))
                    {
                        Directory.CreateDirectory(uploadsDir);
                    }

                    using (var stream = new FileStream(filePath, FileMode.Create))
                    {
                        file.CopyTo(stream);
                    }

                    //string extractedText = ExtractTextFromImage(filePath);
                    //string monetaryValues = FindMonetaryValues(extractedText);

                    //ViewBag.Result = monetaryValues;
                }
                catch (Exception e)
                {
                    ViewBag.Result = "Erro ao processar o arquivo: " + e.Message;
                }
            }

            return View("Index");
        }

        //private string ExtractTextFromImage(string filePath)
        //{
        //    string resultText = string.Empty;

        //    try
        //    {
        //        // Initialize the OCR engine with the LEAD engine
        //        using (var ocrEngine = new OcrEngine(OcrEngineType.LEAD))
        //        {
        //            // Startup the OCR engine with required license key (if needed)
        //            ocrEngine.Startup(null);

        //            // Set OCR options, including the language
        //            ocrEngine.Options.Languages.Add("por"); // Portuguese language code

        //            // Load the image using Leadtools codecs
        //            using (var codec = new RasterCodecs())
        //            {
        //                using (var image = codec.Load(filePath, CodecsLoadOptions.Default))
        //                {
        //                    // Process the image with OCR engine
        //                    using (var page = ocrEngine.Process(image, OcrEngineType.LEAD))
        //                    {
        //                        resultText = page.Text;
        //                    }
        //                }
        //            }

        //            // Shutdown the OCR engine
        //            ocrEngine.Shutdown();
        //        }
        //    }
        //    catch (Exception e)
        //    {
        //        resultText = "Erro ao processar a imagem: " + e.Message;
        //    }
        //    catch (OcrException ex)
        //    {
        //        // Tratar a exceção específica do OCR
        //        Console.WriteLine("Ocorreu um erro durante o processamento OCR: " + ex.Message);
        //    }
        //    catch (Exception ex)
        //    {
        //        // Tratar outras exceções
        //        Console.WriteLine("Ocorreu um erro inesperado: " + ex.Message);
        //    }

        //    return resultText;
        //}

        private string FindMonetaryValues(string text)
        {
            if (string.IsNullOrEmpty(text))
            {
                return "Nenhum texto extraído.";
            }

            // Regex pattern to find values like R$ 123,45
            string pattern = @"R\$\s?\d+(?:,\d{2})?";
            var matches = Regex.Matches(text, pattern);

            if (matches.Count > 0)
            {
                return string.Join(", ", matches);
            }
            else
            {
                return "Nenhum valor monetário encontrado.";
            }
        }
    }
}