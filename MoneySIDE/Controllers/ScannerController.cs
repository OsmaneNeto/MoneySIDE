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
using SixLabors.ImageSharp.Processing.Processors.Quantization;
using Microsoft.AspNetCore.Identity;
using MoneySIDE.Areas.Identity.Data;
using MoneySIDE.Models; 

namespace MoneySIDE.Controllers
{
    [Authorize]
    public class ScannerController : Controller
    {
        private readonly IWebHostEnvironment _hostingEnvironment;
		private readonly ApplicationDbContext _context;
		private readonly UserManager<IdentityUser> _userManager;

        public ScannerController(IWebHostEnvironment hostingEnvironment, ApplicationDbContext context, UserManager<IdentityUser> userManager)
        {
            _hostingEnvironment = hostingEnvironment;
            _context = context; // Inicializando o contexto
            _userManager = userManager; // Inicializando o UserManager
        }


        public IActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Upload(IFormFile file)
        {
        	if (file != null && file.Length > 0)
        	{
        		string filePath = null;
        		try
        		{
        			// Diretório de uploads
        			string uploadsDir = Path.Combine(_hostingEnvironment.WebRootPath, "uploads");
        			filePath = Path.Combine(uploadsDir, file.FileName);

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

        			// Debug: Exibir o texto extraído
        			ViewBag.ExtractedText = extractedText;

        			// Identificar o tipo de comprovante
        			string comprovanteTipo = IdentificarTipoComprovante(extractedText);

             		// Encontrar valores monetários
        			string monetaryValues = FindMonetaryValues(extractedText);

        			// Encontrar o nome do banco
        			string bankName = FindBankName(extractedText);

        			// Encontrar o nome do pagador
        			string payerName = FindPayerName(extractedText);

        			// Encontrar o nome do destinatário
        			string recipientName = FindRecipientName(extractedText);

        			// Encontrar o ID da transação
        			string transactionId = FindTransactionId(extractedText);

                    // Criar um novo objeto Comprovante
                    var comprovante = new Comprovante
                    {
                        Valor = monetaryValues,
                        NomeRemetente = payerName,
                        NomeBanco = bankName,
                        TipoComprovante = comprovanteTipo,
                        DataCadastro = DateTime.Now,
                        UserId = _userManager.GetUserId(User) // Obtendo o UserId do usuário logado
                    };

                    // Adicionar ao contexto e salvar
                    _context.Comprovantes.Add(comprovante);
                    _context.SaveChanges();

                    ViewBag.Result = "Comprovante cadastrado com sucesso!";



                    ViewBag.Result = $"Informações encontradas:\nTipo de Comprovante: {comprovanteTipo} \nBanco: {bankName} \nNome do Pagador: {payerName} \nNome do Destinatário: {recipientName} \nValores Monetários: {monetaryValues} \nID de transação: {transactionId}";
        		}
        		catch (Exception e)
        		{
        			ViewBag.Result = "Erro ao processar o arquivo: " + e.Message;
        		}
        		finally
        		{
        			// Certifique-se de que o arquivo é excluído após o processamento
        			if (filePath != null && System.IO.File.Exists(filePath))
        			{
        				System.IO.File.Delete(filePath);
        		}
        		}
        	}
        	else
        	{
        		ViewBag.Result = "Nenhum arquivo selecionado.";
        	}

        	return View("Index");
        }


       

                    
                







        //Nome do pagador
        private string FindPayerName(string text)
		{
			if (string.IsNullOrEmpty(text))
			{
				return "Nenhum texto extraído.";
			}

			// Expressão regular para encontrar o nome do pagador
			// Pode precisar ajustar conforme os padrões do seu documento
			string pattern = @"(?i)(?:Nome|Pagador|Beneficiário|De)\s*[:\-]?\s*([A-Z][a-z]+\s+[A-Z][a-z]+(?:\s+[A-Z][a-z]+)*)";

			var match = Regex.Match(text, pattern);
			if (match.Success)
			{
				return match.Groups[1].Value.Trim();
			}
			else
			{
				return "Nome do pagador não encontrado.";
			}
		}

		//Nome do Banco
		private string FindBankName(string text)
		{
			if (string.IsNullOrEmpty(text))
			{
				return "Nenhum texto extraído.";
			}

			// Expressão regular para possíveis nomes de bancos
			// Adapte o padrão conforme os nomes dos bancos que você espera encontrar
			string pattern = @"(Banco\s*(do\s*)?(Brasil|Inter|Safra|BTG\s*Pactual|Nacional\s*de\s*Desenvolvimento\s*Econômico\s*e\s*Social\s*\(BNDES\)|HSBC|Citibank|JPMorgan\s*Chase|Deutsche\s*Bank|Barclays|Goldman\s*Sachs|Santander|Bradesco|Itaú\s*Unibanco|Caixa\s*Econômica\s*Federal))";

			var match = Regex.Match(text, pattern, RegexOptions.IgnoreCase);
			if (match.Success)
			{
				return match.Value.Trim();
			}
			else
			{
				return "Nome do banco não encontrado.";
			}
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



		//private string IdentificarTipoComprovante(string texto)
		//{
		//    var tipos = new Dictionary<string, string>
		//    {

		//        { "TED", @"\b(TED|Transferência Eletrônica Disponível)\b" },
		//        { "DOC", @"\b(DOC|Documento de Ordem de Crédito)\b" },
		//        { "PIX", @"\bPIX\b" },
		//        { "PayPal", @"\bPayPal\b" },
		//        { "Skrill", @"\bSkrill\b" },
		//        { "Neteller", @"\bNeteller\b" },
		//        { "Apple Pay", @"\bApple Pay\b" },  
		//        { "Google Pay", @"\bGoogle Pay\b" },
		//        { "Samsung Pay", @"\bSamsung Pay\b" },
		//        { "Débito", @"\bDébito\b" },
		//        { "Crédito", @"\bCrédito\b" },
		//        { "Dinheiro", @"\bDinheiro\b" },
		//        { "Bitcoin", @"\bBitcoin\b" },
		//        { "Ethereum", @"\bEthereum\b" },
		//        { "WhatsApp Pay", @"\bWhatsApp Pay\b" },
		//        { "Facebook Pay", @"\bFacebook Pay\b" },
		//        { "Cheque", @"\bCheque\b" }
		//    };

		//    foreach (var tipo in tipos)
		//    {
		//        if (Regex.IsMatch(texto, tipo.Value, RegexOptions.IgnoreCase))
		//        {
		//            return tipo.Key;
		//        }
		//    }

		//    return "Desconhecido";
		//}


		//Cria e retorna as opções de regex baseadas na sensibilidade a maiúsculas/minúsculas.
		public static RegexOptions GetRegExOptions(bool isCaseSensitive)
		{
			// Cria uma nova opção
			var options = RegexOptions.Multiline; // Exemplo, se precisar de multiline

			// Se não for sensível a maiúsculas/minúsculas
			if (!isCaseSensitive)
				options |= RegexOptions.IgnoreCase;

			// Retorna as opções
			return options;
		}


		//Usa uma tupla para armazenar o padrão de regex e a sensibilidade.
		private static readonly Dictionary<string, (string Padrao, bool CaseSensitive)> TiposComprovante = new()
        {
	{ "Boleto", (@"\b(boleto|código de barras|banco)\b", false) },
	{ "TED", (@"\b(TED|Transferência Eletrônica Disponível)\b", false) },
	{ "DOC", (@"\b(DOC|Documento de Ordem de Crédito)\b", false) },
	{ "PIX", (@"\bPIX\b", false) },
	{ "PayPal", (@"\bPayPal\b", false) },
	{ "Skrill", (@"\bSkrill\b", false) },
	{ "Neteller", (@"\bNeteller\b", false) },
	{ "Apple Pay", (@"\bApple Pay\b", false) },
	{ "Google Pay", (@"\bGoogle Pay\b", false) },
	{ "Samsung Pay", (@"\bSamsung Pay\b", false) },
	{ "Débito", (@"\bDébito\b", false) },
	{ "Crédito", (@"\bCrédito\b", false) },
	{ "Dinheiro", (@"\bDinheiro\b", false) },
	{ "Bitcoin", (@"\bBitcoin\b", false) },
	{ "Ethereum", (@"\bEthereum\b", false) },
	{ "WhatsApp Pay", (@"\bWhatsApp Pay\b", false) },
	{ "Facebook Pay", (@"\bFacebook Pay\b", false) },
	{ "Cheque", (@"\bCheque\b", false) },
	{ "Santander", (@"\bSantander\b", false) },
	{ "Cielo", (@"\bCielo\b", false) }
		};

		//Usa a função para obter as opções e aplicar a regex.
		private string IdentificarTipoComprovante(string texto)
		{
			foreach (var tipo in TiposComprovante)
			{
				// Obtenha as opções de regex
				var regexOptions = GetRegExOptions(tipo.Value.CaseSensitive);

				if (Regex.IsMatch(texto, tipo.Value.Padrao, regexOptions))
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

		// Nome do destinatário
		private string FindRecipientName(string text)
		{
			if (string.IsNullOrEmpty(text))
			{
				return "Nenhum texto extraído.";
			}

			// Expressão regular para encontrar o nome do destinatário
			string pattern = @"(?i)(?:Destinatário|Recebedor|Nome do Destinatário|Beneficiário)\s*[:\-]?\s*([A-Z][a-z]+\s+[A-Z][a-z]+(?:\s+[A-Z][a-z]+)*)";

			var match = Regex.Match(text, pattern);
			if (match.Success)
			{
				return match.Groups[1].Value.Trim();
			}
			else
			{
				return "Nome do destinatário não encontrado.";
			}
		}

		// ID da transação
		private string FindTransactionId(string text)
		{
			if (string.IsNullOrEmpty(text))
			{
				return "Nenhum texto extraído.";
			}

			// Expressão regular para encontrar o ID da transação
			string pattern = @"(?i)(?:ID da Transação|Código de Transação|Número de Transação)\s*[:\-]?\s*([\w\-]+)";

			var match = Regex.Match(text, pattern);
			if (match.Success)
			{
				return match.Groups[1].Value.Trim();
			}
			else
			{
				return "ID da transação não encontrado.";
			}
		}


	}
}
