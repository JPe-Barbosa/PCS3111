#include "MemoriaDeInstrucoes.h"
#include <iostream>

MemoriaDeInstrucoes::MemoriaDeInstrucoes(int tamanho){
    this->tamanho = tamanho;
    this->instrucao = new Instrucao*[tamanho];

    for(int i = 0; i < tamanho; i++) this->instrucao[i] = NULL;
}

MemoriaDeInstrucoes::~MemoriaDeInstrucoes(){
    for(int i = 0; i < this->tamanho; i++) delete this->instrucao[i];
    delete[] instrucao;
}

int MemoriaDeInstrucoes::getTamanho(){
    return this->tamanho;
}

Instrucao* MemoriaDeInstrucoes::ler(int posicao){
    if(posicao < 0 || posicao > this->tamanho) return NULL;
    return this->instrucao[posicao];
}

bool MemoriaDeInstrucoes::escrever(int posicao, Instrucao* d){
    if(posicao < 0 || posicao > this->tamanho) return false;
    
    if(this->instrucao[posicao] != NULL) delete this->instrucao[posicao];

    this->instrucao[posicao] = d;
    return true;
}