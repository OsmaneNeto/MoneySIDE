using System;
using Microsoft.EntityFrameworkCore;
using MoneySIDE.Models;

namespace MoneySIDE.Data
{
    public class ApplicationContext : DbContext
    {
        //rejeitado
        //public DbSet<Usuario> Usuarios { get; set; }

        public ApplicationContext(DbContextOptions<ApplicationContext> options)
            : base(options)
        {
        }

        public DbSet<MoneySIDE.Models.Usuario> Usuarios { get; set; } = default!;//Define um dbset chamando Usuarios
        //que por sua vez representa a tabela de um banco
        //O uso do default! no DbSet indica que a propriedade nunca será nula.
        //É uma boa prática para evitar erros de acesso a objetos nulos.


        //rejeitado
        //protected override void OnModelCreating(ModelBuilder modelBuilder)
        //{
        //    modelBuilder.ApplyConfiguration(new UsuarioConfig());
        //}

    }
}
