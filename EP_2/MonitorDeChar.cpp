
#include<iostream>
#include "MonitorDeChar.h"

using namespace std;

MonitorDeChar::MonitorDeChar(){}
MonitorDeChar::~MonitorDeChar(){}

void MonitorDeChar::escrever(Dado* d){
    cout << static_cast<char>(d->getValor());
} 


