#include "Filme.h"

#include <iostream>

Filme::Filme(string nome, int duracao) : nome(nome), duracao(duracao) {
}

Filme::~Filme(){
    cout << "Filme " << nome << " destruido" << endl;
}

string Filme::getNome() const {
    return nome;
}

int Filme::getDuracao() const {
    return duracao;
}

void Filme::imprimir() const {
    cout << nome << " - " << duracao << " minutos" << endl;
}

