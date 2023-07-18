#include "Filme.h"
#include <string>
#include <iostream>

Filme::Filme(string nome, int duracao):
    nome(nome), duracao(duracao){
}

Filme::~Filme(){
    cout << "Filme " << this->getNome() << " destruido" << endl; 
}

string Filme::getNome() {
    return this->nome;
}

int Filme::getDuracao() {
    return this->duracao;
}

void Filme::imprimir() {
    cout << this->nome << " - " << this->duracao << " minutos" << endl;
}
