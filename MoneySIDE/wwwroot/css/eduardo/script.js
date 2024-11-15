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

const boxes = document.querySelectorAll('')



