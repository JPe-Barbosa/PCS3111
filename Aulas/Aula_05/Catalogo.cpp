#include "Catalogo.h"
#include "Filme.h"
#include <iostream>
using namespace std;

Catalogo::Catalogo(int quantidadeMaxima){
    this->quantidadeMaxima = quantidadeMaxima;
    this->quantidade = 0;
    this->filmes= new Filme *[quantidadeMaxima];
}
Catalogo::~Catalogo(){
    cout << "Catalogo com " << this->quantidade << " filme(s) destruido" << endl; 
    for(int i = 0; i < this->quantidade; i++){
        delete this->filmes[i];
    }
    delete[] filmes;
    
}

Filme** Catalogo::getFilmes() {
    return this->filmes;
}

int Catalogo::getQuantidadeFilmes() {
    return this->quantidade;
}

int Catalogo::getQuantidadeMaximaFilmes() {
    return this->quantidadeMaxima;
}

bool Catalogo::adicionar(Filme* filme) {
    if(this->quantidade >= this->quantidadeMaxima)
        return false;

    this->filmes[this->quantidade++] = filme;
    return true;
}

void Catalogo::imprimir() {
    cout << "Catalogo com " << this->quantidade << " filmes" << endl;
    for(int i = 0; i < this->quantidade; i++)
        this->filmes[i]->imprimir();
}
