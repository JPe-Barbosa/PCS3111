#include "MemoriaDeDados.h"
#include <iostream>
#include <string>
#include "Dado.h"
using namespace std;

MemoriaDeDados::MemoriaDeDados(int tamanho){
    this->tamanho = tamanho;
    dados = new Dado*[this->tamanho];
    for(int i = 0; i < this->tamanho; i++) dados[i] = NULL;
}

MemoriaDeDados::~MemoriaDeDados(){
    for(int i = 0; i < this->tamanho; i++) delete this->dados[i];
    delete[] dados;
}

int MemoriaDeDados::getTamanho(){
    return this->tamanho;
}

Dado* MemoriaDeDados::ler(int posicao){
    if(posicao < 0 || posicao > this->tamanho) return NULL;
    return this->dados[posicao];
}

bool MemoriaDeDados::escrever(int posicao, Dado* d){
    if(posicao < 0 || posicao > this->tamanho) return false;
    
    if(this->dados[posicao] != NULL) delete this->dados[posicao];
    
    this->dados[posicao] = d;
    return true;
}

void MemoriaDeDados::imprimir(){
    for(int i = 0; i < this->tamanho; i++){
        if(this->dados[i] == NULL) cout << i << ": -" << endl;
        else {
        cout << i << ": "; 
        dados[i]->imprimir(); 
        cout << endl;
        }
    }
}