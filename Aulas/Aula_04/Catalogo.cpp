#include "Catalogo.h"
#include <iostream>
#include <string>

using namespace std;

bool Catalogo::adicionar(Filme* f){
    if(this->quantidade < NUMERO_MAXIMO_VALORES){
        for(int i = 0; i < this->quantidade; i++){
            if(this->filmes[i] == f){
                return false;
            }
        }
        this->filmes[this->quantidade] = f;
        this->quantidade += 1;
    } else{
        return false;
    }
    return true;
}
int Catalogo::getQuantidade(){
    return this->quantidade;
}
int Catalogo::getDuracaoTotal(){
    int total = 0;
    if (this->quantidade == 0){
        return 0;
    }
    for(int i = 0; i < this->quantidade; i++){
        total += this->filmes[i]->getDuracao();
    }

    return total;
}
void Catalogo::imprimir(){
    cout << "Catalogo com " << this->getQuantidade() << " filmes - " << this->getDuracaoTotal() << " minutos no total" << endl;
    for(int i = 0; i < this->quantidade; i++){
        this->filmes[i]->imprimir();
    }
}