#include "Filme.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Filme::Filme(string nome, int duracao)  {
if(duracao <= 0){
    throw new invalid_argument("duracao invalida");
}
this->nome= nome;
this->duracao= duracao;
this->visualizacoes = 0;
}

Filme::~Filme() {
}

string Filme::getNome() const {
    return this->nome;
}

int Filme::getDuracao() const {
    return this->duracao;
}

int Filme::getVisualizacoes() const {
    return this->visualizacoes;
}

void Filme::assistir(int tempo) {
    if(tempo < 0 || tempo > this->duracao){
        throw new invalid_argument("tempo invalido");
    }
    double porcentagemAssistida = ((double) tempo)/duracao;
    if (porcentagemAssistida >= 0.7) visualizacoes++;
}

void Filme::imprimir() const {
    cout << this->nome << " - " << this->duracao << " minutos" << endl;
}

