#include "Dado.h"
#include <iostream>
using namespace std;

Dado::Dado(int valor){
    this->valor = valor;
}
int Dado::getValor(){
    return this->valor;
}

void Dado::imprimir(){
    cout << this->valor;
}

Dado::~Dado(){}