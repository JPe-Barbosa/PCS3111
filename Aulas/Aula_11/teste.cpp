#include "Catalogo.h"
#include "Filme.h"
#include "Plano.h"


void teste1(){
    Catalogo* c1 = new Catalogo("Sci-Fi");
    Filme* f1 = new Filme("Star Wars", 120);
    c1->adicionar(f1);
    Filme* f2 = new Filme("Planeta dos Macacos", 90);
    c1->adicionar(f2);
    c1->imprimir();
    delete c1;
    delete f1;
    delete f2;
}

void teste2(){
    Plano* p1 = new Plano("Basico");
    Catalogo* c1 = new Catalogo("Sci-Fi");
    Filme* f1 = new Filme("Star Wars", 120);
    c1->adicionar(f1);
    Filme* f2 = new Filme("Planeta dos Macacos", 90);
    c1->adicionar(f2);
    Catalogo* c2 = new Catalogo("Guerra");
    Filme* f3 = new Filme("A Lista de Schindler", 120);
    c2->adicionar(f3);
    p1->adicionar(c1);
    p1->adicionar(c2);
    p1->imprimir();
    delete p1;
    delete c1;
    delete c2;
    delete f1;
    delete f2;
    delete f3;
}

// int main() {
//     teste2(); // Escolha o teste a ser executado
//     return 0;
// }
