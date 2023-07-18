#include "Filme.h"

#include <iostream>

Filme::Filme(string nome, int duracao) : Item(nome, duracao){
}

Filme::~Filme() {
}
void Filme::imprimir() {
     cout << this->nome << " - " << this->duracao << " minutos" << endl;

}
