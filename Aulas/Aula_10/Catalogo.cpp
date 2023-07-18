#include "Catalogo.h"

#include <iostream>

Catalogo::Catalogo(int quantidadeMaxima) : quantidadeMaxima(quantidadeMaxima), quantidade(0) {
    this->filmes = new Filme*[quantidadeMaxima];
}

Catalogo::~Catalogo() {
    for (int i = 0; i < quantidade; i++) {
        delete this->filmes[i];
    }
    delete this->filmes;
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

int Catalogo::getDuracaoTotal() {
    int total = 0;
    for(int i = 0; i < this->quantidade; i++)
        total += this->filmes[i]->getDuracao();

    return total;
}

bool Catalogo::adicionar(Filme* filme) {
    if(this->quantidade >= this->quantidadeMaxima)
        return false;

    this->filmes[this->quantidade++] = filme;
    return true;
}

void Catalogo::imprimir() {
    cout << "Catalogo com " << this->quantidade << " - " << this->getDuracaoTotal() << " minutos no total" << endl;
    for(int i = 0; i < this->quantidade; i++)
        this->filmes[i]->imprimir();
}
