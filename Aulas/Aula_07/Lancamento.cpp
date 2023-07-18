#include "Lancamento.h"

Lancamento::Lancamento(string nome, int duracao) : Filme(nome, duracao) {
}

Lancamento::~Lancamento(){
}

void Lancamento::assistir(int tempo){
    if(tempo > 0 && tempo <= this->duracao){
        this->visualizacoes++;
    }
}