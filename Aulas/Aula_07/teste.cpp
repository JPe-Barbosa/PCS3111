#include "Catalogo.h"
#include "Filme.h"
#include "Lancamento.h"
#include <iostream>

void teste1(){
    Catalogo* c1 = new Catalogo(2);
    Filme* f1 = new Filme("Madagascar", 100);
    f1->assistir(20);
    f1->assistir(30);
    f1->assistir(50);
    c1->adicionar(f1);
    c1->adicionar("Animacao");
    c1->imprimir();
    delete f1;
    delete c1;


}

void teste2(){
    Catalogo* c1 = new Catalogo(2);
    Filme* f1 = new Filme("Madagascar", 100);
    f1->assistir(20);
    f1->assistir(30);
    f1->assistir(50);
    c1->adicionar(f1);
    c1->adicionar("Animacao");
    Filme* l1 = new Lancamento("Tempos Modernos", 100);
    l1->assistir(20);
    l1->assistir(30);
    l1->assistir(50);
    c1->adicionar(l1);
    c1->imprimir();
    delete f1;
    delete c1;
    delete l1;
}

void teste3() {
    int quantidadedeLancamentos = 0;
    Catalogo* c1 = new Catalogo(2);
    Lancamento** l = c1->getLancamentos(quantidadedeLancamentos);
    cout << quantidadedeLancamentos << endl;
    Filme* f1 = new Filme("Madagascar", 100);
    c1->adicionar(f1);
    l = c1->getLancamentos(quantidadedeLancamentos);
    cout << quantidadedeLancamentos << endl;
    Lancamento* l1 = new Lancamento("Tempos Modernos", 100);
    c1->adicionar(l1);
    l = c1->getLancamentos(quantidadedeLancamentos);
    cout << quantidadedeLancamentos << endl;
    delete f1;
    delete l1;
    delete c1;
}
/*
int main(){
    teste3(); // Escolha o teste do exercicio a ser testado
    return 0;
}
*/
