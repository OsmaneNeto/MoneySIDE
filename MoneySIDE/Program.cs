using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Options;

using MoneySIDE.Models;
using Microsoft.AspNetCore.Identity;
using MoneySIDE.Areas.Identity.Data;
using CodeData.Services;
using MoneySIDE.Services;





var builder = WebApplication.CreateBuilder(args);
var connectionString = builder.Configuration.GetConnectionString("ApplicationDbContextConnection") ?? throw new InvalidOperationException("Connection string 'ApplicationDbContextConnection' not found.");

builder.Services.AddDbContext<ApplicationDbContext>(options => options.UseMySQL(connectionString));
//SendGrid
builder.Services.AddTransient<SendGridEmailSender>();

builder.Services.AddDefaultIdentity<IdentityUser>(options => options.SignIn.RequireConfirmedAccount = true).AddEntityFrameworkStores<ApplicationDbContext>();
builder.Services.AddRazorPages();

// Add services to the container.
builder.Services.AddControllersWithViews();

//ComprovantServies
builder.Services.AddScoped<ComprovanteService>(); // Adicione esta linha
// Registro do ComprovanteService


var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
    // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
    app.UseHsts();
}

app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseRouting();

app.UseAuthorization();

app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Leanding}/{action=Index}/{id?}");
app.MapRazorPages();
app.Run();
