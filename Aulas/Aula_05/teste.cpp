#include <string>
#include "Filme.h"
#include "Catalogo.h"

void teste1() {
Filme *bao = new Filme("Bao", 8);
bao->imprimir();
delete bao;
}

void teste2() {
    Filme *f1 = new Filme("O Magico de Oz",  100);
    Filme *f2 = new Filme("Alien",  120);
    Filme *f3 = new Filme("E o Vento Levou",  240);
    Filme *f4 = new Filme("Viajem ao Centro da Terra",  90);
    
    Catalogo *cat = new Catalogo(4);
    cat->adicionar(f1);
    cat->adicionar(f2);
    cat->adicionar(f3);
    cat->adicionar(f4);

    delete cat; 
}
/*
int main() {
    teste1();
    teste2();
    return 0;
}
*/



