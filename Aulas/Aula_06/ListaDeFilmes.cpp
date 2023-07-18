#include "ListaDeFilmes.h"

#include <iostream>

using namespace std;

ListaDeFilmes::ListaDeFilmes(int quantidadeMaxima):
    quantidadeMaxima(quantidadeMaxima),
    quantidadedeFilmes(0),
    filmes(new Filme *[quantidadeMaxima]){
}

ListaDeFilmes::~ListaDeFilmes(){
    delete filmes;
}

Filme** ListaDeFilmes::getFilmes(){
    return filmes;
}

int ListaDeFilmes::getQuantidadeDeFilmes(){
    return this->quantidadedeFilmes;
}

bool ListaDeFilmes::adicionar(Filme *f){
    if(quantidadedeFilmes >= quantidadeMaxima)return false;
    for (int i = 0; i < quantidadedeFilmes; i++)if(filmes[i] == f) return false;
    filmes[quantidadedeFilmes] = f;
    quantidadedeFilmes++;
    return true;
}

bool ListaDeFilmes::remover(Filme *f){
    for(int i = 0; i < quantidadedeFilmes; i++){
        if (filmes[i] == f){
            for(int j = i; j < quantidadedeFilmes; j++) filmes[j] = filmes[j+1];
            quantidadedeFilmes--;
            return true;
        }
    }
    return false;
}

void ListaDeFilmes::imprimir(){
    cout << "Lista com " << this->getQuantidadeDeFilmes() << " filmes a assistir:" << endl;
    for (int i = 0; i < this->getQuantidadeDeFilmes(); i++){
        cout << "Filme " << i + 1 << ": ";
        this->getFilmes()[i]->imprimir();
        cout << endl;
    }
}

