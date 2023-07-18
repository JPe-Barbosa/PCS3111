#include "Plano.h"
#include <list>
#include <stdexcept>
#include <iostream>

using namespace std;

Plano::Plano(string tipo):tipo(tipo){
    catalogos = new list <Catalogo*>();
}

Plano::~Plano() {
    delete catalogos;
}

void Plano::adicionar(Catalogo *c){
    list<Catalogo*>::iterator i = catalogos->begin();
    while(i != catalogos->end()){
        if((*i)->getNome() == c->getNome())
            throw new invalid_argument("a");
        i++;
    }
    catalogos->push_back(c);
}

list<Catalogo*>* Plano::getCatalogos(){
    return catalogos;
}

void Plano::imprimir(){
    cout << "Plano " << this->tipo << " - " << catalogos->size() << " Catalos" << endl;
    list<Catalogo*>::iterator i = catalogos->begin();
    while(i != catalogos->end()){
        (*i)->imprimir();
        i++;
    }
        
}
