using MoneySIDE.Data;
using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;


namespace MoneySIDE.Models
{
    [Table("Usuario")]//nome da tabela

    public class Usuario
    {
        [Display(Name = "IdUsuario")]
        public int IdUsuario { get; set; }

        [Display(Name = "Nome")]
        public string Nome { get; set; }

        [DataType(DataType.Password)]//Indica que o atributo deve ser tratado como uma senha na interface do usuário e por isso bem ocultado

        [Display(Name = "Senha")]
        public String Senha { get; set; }

        [Display(Name = "Email")]
        public String Email { get; set; }

        [Display(Name = "Login")]
        public String Login { get; set; }
    }
}