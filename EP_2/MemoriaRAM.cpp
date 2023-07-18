#include"MemoriaRAM.h"
#include "Dado.h"
#include <stdexcept>                    
#include <list>
#include <iostream>

MemoriaRAM::MemoriaRAM(int tamanho):tamanho(tamanho){
    dados = new Dado *[tamanho];
    for(int i = 0; i < tamanho; i++){
        dados[i] = NULL;
    }   
}

MemoriaRAM::~MemoriaRAM(){
    for(int i = 0; i <tamanho; i++){
        delete dados[i];
    }
    delete dados;
}

int MemoriaRAM::getTamanho(){
    return this->tamanho;
    
}

Dado* MemoriaRAM::ler(int posicao){
    if(posicao < 0 || posicao >= getTamanho())throw new logic_error("Mensagem de erro");
    return dados[posicao];
}

void MemoriaRAM::escrever(int posicao, Dado* d){
    if(posicao < 0 || posicao >= getTamanho())throw new logic_error("Mensagem de erro");
    if(dados[posicao] == NULL){
        dados[posicao] = d;
    }else{
        delete dados[posicao];
        dados[posicao] = d;
    }
}

void MemoriaRAM::escrever(list<Dado*>* dados){
    if((int)dados->size() > this->tamanho)throw new logic_error("mensagem de erro");
    list<Dado*>::iterator i = dados->begin();
    int j = 0;
    while(i != dados->end()){
        this->dados[j] = (*i);
        j++;
        i++;
    }
} 

void MemoriaRAM::imprimir(){
    for(int i = 0; i < getTamanho(); i++){
        if(this->dados[i] == NULL){ 
            cout << i << ": -" << endl;
        }else{
            cout << i << ": ";
            dados[i]->imprimir();
            cout << endl;
        }
    }
} 