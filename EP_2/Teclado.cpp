#include<stdexcept>
#include<iostream>
#include "Teclado.h"
#include "Dado.h"
using namespace std;

Teclado::Teclado(){}
Teclado::~Teclado(){}

void Teclado::escrever(Dado *d){
throw new logic_error("mensagem de erro");
}

Dado* Teclado::ler(){
    int numero;
    cout << "Digite um numero: ";
    cin >> numero;
    Dado *d = new Dado(numero);
    //cout <<"teste 1";
    return d;
}