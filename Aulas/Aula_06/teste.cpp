#include <iostream>
#include "Filme.h"
#include "Lancamento.h"
#include "ListaDeFilmes.h"

using namespace std;

void teste1() {
Filme* f1 = new Lancamento(12,2003, "Sonic 2",110);
Lancamento* l1 = static_cast <Lancamento*>(f1);
l1->imprimir();
delete l1;
}

void teste2() {
    Filme* f1 = new Filme("Pequena Sereia", 83);
    Lancamento* l1 = new Lancamento(12,2003, "Sonic 2",110);
    ListaDeFilmes* li1 = new ListaDeFilmes(2);
    li1->adicionar(f1);
    li1->adicionar(l1);
    li1->imprimir();
    li1->remover(f1);
    li1->imprimir();
    delete li1;
    delete f1;
    delete l1;
}

int main() {
    teste2(); //Substitua pelo teste que deseja chamar
    return 0;
}

