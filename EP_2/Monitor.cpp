#include "Monitor.h"
#include <stdexcept> 
#include <iostream>
using namespace std;

Monitor::Monitor(){}
Monitor::~Monitor(){}

Dado* Monitor::ler(){
    throw new logic_error("mensagem de erro");
}
void Monitor::escrever(Dado* d){
    cout << d->getValor();
}