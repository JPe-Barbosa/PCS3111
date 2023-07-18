#include <iostream>
#include <string>
#include "Filme.h"
#include "Catalogo.h"
using namespace std;

void teste1() {
    Filme *Bao = new Filme;
    Bao->setNome("Bao");
    Bao->setDuracao(8);

    Bao->imprimir();
}

void teste2() {
    Filme *fil1 = new Filme;
    Filme *fil2 = new Filme;
    fil1->setNome("O Magico de Oz");
    fil2->setNome("Alien");
    fil1->setDuracao(100);
    fil2->setDuracao(120);

    Catalogo *cat = new Catalogo;
    cat->adicionar(fil1);
    cat->adicionar(fil2);

    cat->imprimir();
}

int main() {
    teste1();
    teste2();
    return 0;
}