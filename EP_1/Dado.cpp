#include "Dado.h"
#include <iostream>

int Dado::getValor(){
    return this->valor;
}

void Dado::imprimir(){
    cout << getValor();
}

Dado::Dado(int valor){
    this->valor = valor;
}

Dado::~Dado(){}