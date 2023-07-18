#include <vector>
#include "Memoria.h"
#include "MemoriaRAM.h"
#include "Dispositivo.h"
#include "ESMapeadaNaMemoria.h"
#include <iostream>
#include <stdexcept>                    


using namespace std;

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM* m):memram(m),dispositivos(new vector<Dispositivo*>){}

ESMapeadaNaMemoria::ESMapeadaNaMemoria(MemoriaRAM* m, vector<Dispositivo*>* dispositivos):memram(m),dispositivos(dispositivos){}

ESMapeadaNaMemoria::~ESMapeadaNaMemoria(){
    delete memram;

    while(!dispositivos->empty()){
        Dispositivo *ultimo = dispositivos->back();
        dispositivos->pop_back();
        delete ultimo;
    }
    delete dispositivos;
}
MemoriaRAM* ESMapeadaNaMemoria::getMemoriaSubjacente(){
    return memram;
}

void ESMapeadaNaMemoria::adicionar(Dispositivo* d){
    dispositivos->push_back(d);
}

vector<Dispositivo*>* ESMapeadaNaMemoria::getDispositivos(){
    return dispositivos;
}

int ESMapeadaNaMemoria::getTamanho(){
    return memram->getTamanho() + dispositivos->size();
}

Dado* ESMapeadaNaMemoria::ler(int posicao){
    if (posicao < 0 || posicao >= getTamanho()) throw new logic_error("mensagem de erro");
    if(posicao < memram->getTamanho()){
        return memram->ler(posicao);
    }else{
        //cout <<"teste 4 " << posicao - memram->getTamanho();
        return dispositivos->at(posicao - memram->getTamanho())->ler();
    }
}

void ESMapeadaNaMemoria::escrever(int posicao, Dado* dado){
    if (posicao < 0 || posicao >= getTamanho()) throw new logic_error("mensagem de erro");
    if(posicao < memram->getTamanho()){
        memram->escrever(posicao, dado);
    }else{
        dispositivos->at(posicao - memram->getTamanho())->escrever(dado);
    }
}

void ESMapeadaNaMemoria::imprimir(){
    memram->imprimir();
}