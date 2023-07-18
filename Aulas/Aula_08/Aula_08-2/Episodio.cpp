#include "Episodio.h"
#include <iostream>

Episodio::Episodio(string nome, int numero):Item(nome, numero){}

void  Episodio::imprimir(){
    cout << this->nome << " - " << this->duracao << " minutos" << endl;
}