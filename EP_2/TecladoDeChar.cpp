#include<stdexcept>
#include<iostream>
#include "TecladoDeChar.h"
#include "Dado.h"
using namespace std;

TecladoDeChar::TecladoDeChar(){}
TecladoDeChar::~TecladoDeChar(){}

Dado* TecladoDeChar::ler(){
    char caractere;
    cout << "Digite um caractere: ";
    cin >> caractere;
    return new Dado(static_cast<int>(caractere));
}