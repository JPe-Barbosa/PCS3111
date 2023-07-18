#include "Lancamento.h"
#include <iostream>


using namespace std;

Lancamento::Lancamento(int preco, int dataDeLancamento, string nome, int duracao):
    Filme(nome,duracao), 
    preco(preco),
    dataDeLancamento(dataDeLancamento){  
}

Lancamento::~Lancamento(){
    
}
int Lancamento::getPreco(){
    return this->preco;
}

int Lancamento::getDataDeLancamento(){
    return this->dataDeLancamento;
}

void Lancamento::imprimir(){
    cout << getNome() << " sai em " << getDataDeLancamento() << " por " << getPreco() << " reais" <<endl;
}
