namespace MoneySIDE.Models
{
    public class Comprovante
    {
        public int Id { get; set; }
        public string Valor { get; set; }
        public string NomeRemetente { get; set; }
        public string NomeBanco { get; set; }
        public string TipoComprovante { get; set; }
        public DateTime? DataCadastro { get; set; }
        public string? UserId { get; set; }
    }
}