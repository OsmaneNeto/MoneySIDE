using System;
using System.ComponentModel.DataAnnotations;
using Microsoft.AspNetCore.Identity;

public class Comprovante
{
	public int Id { get; set; }

	[Required]
	public string Valor { get; set; }

	[Required]
	public string NomeRemetente { get; set; }

	[Required]
	public string NomeBanco { get; set; }

	[Required]
	public string TipoComprovante { get; set; }

	public DateTime DataCadastro { get; set; } = DateTime.UtcNow;

	// Adiciona a propriedade UserId para associar o comprovante ao usuário
	public string UserId { get; set; }

	// Adiciona a relação com o usuário
	public IdentityUser User { get; set; }
}
