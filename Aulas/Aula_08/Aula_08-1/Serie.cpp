#include "Serie.h"
#include <iostream>

Serie::Serie(string nome, int quantidadeMaxima):Item(nome,0),quantidadeMaxima(quantidadeMaxima),quantidade(0),episodios(new Episodio*[quantidadeMaxima]){}

Serie::~Serie(){
    for(int i = 0; i < quantidade; i ++){
        delete episodios[i];
    }
    delete episodios;
}

bool Serie::adicionar(Episodio* ep){
    if(quantidade < quantidadeMaxima){
        this->duracao += ep->getDuracao();
        episodios[quantidade] = ep;
        quantidade++;
        return true;
    }else{
        return false;
    }
}

Episodio** Serie::getEpisodios(){
    return episodios;
}

int Serie::getQuantidadeEpisodios(){
    return quantidade;
}

void Serie::imprimir(){
    cout << nome << " - " << duracao << " minutos - " << quantidade << " episodios" << endl;
    for (int i = 0; i < quantidade; i++){
        cout <<"\t"<< i+1 <<": ";
        episodios[i]->imprimir();
    }
}