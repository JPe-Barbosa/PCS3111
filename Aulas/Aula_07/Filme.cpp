#include "Filme.h"
#include <iostream>

Filme::Filme(string nome, int duracao): nome(nome), duracao(duracao) {
    visualizacoes = 0;
}

Filme::~Filme(){
}

void Filme::assistir(int tempo) {
    double porcentagemAssistida = ((double) tempo)/duracao;
    if (porcentagemAssistida >= 0.7) visualizacoes++;
}

int Filme::getDuracao() {
    return duracao;
}

int Filme::getVisualizacoes() {
    return visualizacoes;
}

void Filme::imprimir(){
    cout << "Filme: " << nome << " - " << duracao << " minutos - " << visualizacoes << " visualizacoes" << endl;
}

string Filme::getNome(){
return nome;
}

