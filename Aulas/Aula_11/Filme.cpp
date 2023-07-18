#include "Filme.h"
#include <iostream>

Filme::Filme(string nome, int duracao) {
    if (nome == "" || duracao <= 0) throw new invalid_argument("Argumento invalido no construtor");
    this->nome = nome;
    this->duracao = duracao;
}

Filme::~Filme(){
}

int Filme::getDuracao() {
    return duracao;
}

void Filme::imprimir(){
    cout << "Filme: " << nome << " - " << duracao << " minutos" << endl;
}

string Filme::getNome(){
return nome;
}

