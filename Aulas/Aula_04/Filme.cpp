#include "Filme.h"
#include <iostream>
#include <string>

using namespace std;

void Filme::imprimir() {
    cout << this->nome << " - " << this->duracao << " minutos" << endl;
}
string Filme::getNome(){
    return this->nome;
}
void Filme::setNome(string nome){
    this->nome = nome;
}
int Filme::getDuracao(){
    return this->duracao;
}
void Filme::setDuracao(int duracao){
    this->duracao = duracao;
}
