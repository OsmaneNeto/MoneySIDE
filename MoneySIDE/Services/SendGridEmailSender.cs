using Microsoft.AspNetCore.Identity.UI.Services;
using SendGrid;
using SendGrid.Helpers.Mail;

namespace CodeData.Services
{
    public class SendGridEmailSender : IEmailSender
    {
        private readonly IConfiguration configuration;
        private readonly ILogger logger;

        public SendGridEmailSender(IConfiguration configuration, ILogger<SendGridEmailSender> logger)
        {
            this.configuration = configuration;
            this.logger = logger;
        }

        public async Task SendEmailAsync(string toEmail, string subject, string message)
        {
            try
            {
                // Obtendo a chave da API do SendGrid
                string sendGridApiKey = "";
                if (string.IsNullOrEmpty(sendGridApiKey))
                {
                    throw new Exception("The 'SendGridApiKey' is not configured. Please check your appsettings.json file.");
                }

                var client = new SendGridClient(sendGridApiKey);
                var msg = new SendGridMessage()
                {
                    From = new EmailAddress("", "MoneySIDE LTDA"),
                    Subject = subject,
                    PlainTextContent = message,
                    HtmlContent = message
                };
                msg.AddTo(new EmailAddress(toEmail));

                // Enviando o e-mail e verificando a resposta
                var response = await client.SendEmailAsync(msg);
                if (response.IsSuccessStatusCode)
                {
                    logger.LogInformation("Email queued successfully");
                }
                else
                {
                    var responseBody = await response.Body.ReadAsStringAsync();
                    logger.LogError($"Failed to send email. Status Code: {response.StatusCode}, Body: {responseBody}");
                }
            }
            catch (Exception ex)
            {
                // Capturando exceções gerais e logando o erro
                logger.LogError(ex, "An error occurred while sending the email.");
                throw; // Opcional: Repropagar a exceção se necessário
            }
        }
    }
}