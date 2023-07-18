#include "BancoDeRegistradores.h"
#include <iostream>
#include <stdexcept>


int BancoDeRegistradores::getValor(int registrador){
    if(registrador < 0 || registrador >= QUANTIDADE_REGISTRADORES) throw new logic_error("Mensagem de erro");
    return registradores[registrador];
}

void BancoDeRegistradores::setValor(int registrador, int valor){
    if(registrador == 0) return;
    if(registrador < 0 || registrador >= QUANTIDADE_REGISTRADORES) throw new logic_error("Mensagem de erro");
    this->registradores[registrador] = valor;
}

void BancoDeRegistradores::imprimir(){
    for(int i = 0; i < QUANTIDADE_REGISTRADORES; i++) cout << i << ": " << getValor(i) << endl;
}

BancoDeRegistradores::BancoDeRegistradores(){
    for(int i = 0; i < QUANTIDADE_REGISTRADORES; i++) this->registradores[i] = 0;
}

BancoDeRegistradores::~BancoDeRegistradores(){
    for(int i = 0; i < QUANTIDADE_REGISTRADORES; i++) registradores[i] = 0;
}