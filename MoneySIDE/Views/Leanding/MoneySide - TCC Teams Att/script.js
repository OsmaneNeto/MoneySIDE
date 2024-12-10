document.addEventListener('DOMContentLoaded', function() {
    const header = document.querySelector('.cabecalho');
    
    window.addEventListener('scroll', function() {
        if (window.scrollY > 50) { // Ajuste o valor conforme necessário
            header.classList.add('cabecalho--scrolled');
        } else {
            header.classList.remove('cabecalho--scrolled');
        }
    });
});

window.onload = function() {
    // Remove o hash da URL, evitando rolagem automática
    if (window.location.hash) {
        history.replaceState(null, null, ' ');
    }
};

const conteudo = document.getElementById('conteudo');
const registerBtn = document.getElementById('register');
const loginBtn = document.getElementById('login');

registerBtn.addEventListener('click', () => {
    conteudo.classList.add("active");
});

loginBtn.addEventListener('click', () => {
    conteudo.classList.remove("active");
});