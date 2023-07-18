#include "BancoDeRegistradores.h"
#include <iostream>


int BancoDeRegistradores::getValor(int registrador){
    if(registrador < 0 || registrador >= 32) return 0;
    return registradores[registrador];
}

void BancoDeRegistradores::setValor(int registrador, int valor){
    if(registrador <= 0 || registrador >= 32) return;
    this->registradores[registrador] = valor;
}

void BancoDeRegistradores::imprimir(){
    for(int i = 0; i < 32; i++) cout << i << ": " << this->getValor(i) <<endl;
}

BancoDeRegistradores::BancoDeRegistradores(){
    for(int i = 0; i < 32; i++) this->registradores[i] = 0;
}

BancoDeRegistradores::~BancoDeRegistradores(){
    for(int i = 0; i < 32; i++) this->registradores[i] = 0;
}