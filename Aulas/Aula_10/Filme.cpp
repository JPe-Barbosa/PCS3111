#include "Filme.h"

#include <iostream>

Filme::Filme(string nome, int duracao) :
    nome(nome), duracao(duracao), visualizacoes(0) {
}

Filme::Filme(string nome, int duracao, int visualizacoes) :
    nome(nome), duracao(duracao), visualizacoes(visualizacoes) {
}

Filme::~Filme() {
}

string Filme::getNome() {
    return this->nome;
}

int Filme::getDuracao() {
    return this->duracao;
}

int Filme::getVisualizacoes() {
    return this->visualizacoes;
}

void Filme::assistir(int tempo) {
    if (((double) tempo) / this->duracao >= 0.7) {
        this->visualizacoes++;
    }
}

void Filme::imprimir() {
    cout << this->nome << " - " << this->duracao << " minutos - " << visualizacoes << " visualizacoes" << endl;
}
