namespace MoneySIDE.Models
{
    public class Transaction
    {
        public string Id { get; set; }
        public string BankName { get; set; }
        public string SenderName { get; set; }
        public string RecipientName { get; set; }
        public string Date { get; set; }
        public string TransactionType { get; set; }
        public string TransactionNature { get; set; }
    }
}
