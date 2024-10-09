using Aspose.Cells; // Certifique-se de ter a referência correta
using MoneySIDE.Models;
using System.Collections.Generic;
using System.IO;
using OfficeOpenXml;
using System.IO;
using Microsoft.PowerBI.Api.Models;

public class Analise
{
    
    public string Remetente { get; set; }
    public string Destinatario { get; set; }
    public decimal Valor { get; set; }
    public DateTime Data { get; set; }

    internal byte[] GenerateExcelChart(List<Comprovante> comprovantes)
    {
        throw new NotImplementedException();
    }
}
