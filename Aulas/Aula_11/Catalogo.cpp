#include "Catalogo.h"
#include <iostream>
#include <stdexcept>

Catalogo::Catalogo(string nome) : nome(nome){
    filmes = new vector<Filme*>();
}

Catalogo::~Catalogo(){
    delete filmes;
}

string Catalogo::getNome(){
    return nome;
}

void Catalogo::adicionar(Filme *f) {
    for(unsigned int i = 0; i < filmes->size(); i++)
        if(filmes->at(i) == f) throw new invalid_argument("Filme ja existe");
    filmes->push_back(f);

    // for (int i = 0; i < quantidadeFilmes; i++)
    //     if (filmes[i] == f) throw new invalid_argument("Filme ja existe");
    // filmes[quantidadeFilmes++] = f;
}

int Catalogo::getDuracaoTotal(){
    int duracaoTotal = 0;
    for(unsigned int i = 0; i < filmes->size(); i++)
        duracaoTotal += filmes->at(i)->getDuracao();
    return duracaoTotal;
}

vector <Filme*>* Catalogo::getFilmes(){
    return filmes;
}

void Catalogo::imprimir(){
    cout << "Catalogo " << nome << " - " << filmes->size() << " filmes" << endl;
    for(unsigned int i = 0; i < filmes->size(); i++)
       filmes->at(i)->imprimir();
    cout << "Total: " << this->getDuracaoTotal() << " minutos" << endl;
}
