#include "Catalogo.h"
#include "Lancamento.h"
#include <iostream>

//Faca os includes necessarios e implemente os metodos pedidos no enunciado

Catalogo::Catalogo(int tamanhoMaximo) : tamanhoMaximo(tamanhoMaximo) {
    filmes = new Filme*[tamanhoMaximo];
    categorias = new string[tamanhoMaximo];
    quantidadeFilmes = 0;
    quantidadeCategorias = 0;
}

Catalogo::~Catalogo(){
    delete[] filmes;
    delete[] categorias;
}

bool Catalogo::adicionar(Filme *f) {
    if (quantidadeFilmes >= tamanhoMaximo) return false;
    for (int i = 0; i < quantidadeFilmes; i++)
        if (f == filmes[i]) return false;
    filmes[quantidadeFilmes++] = f;
    return true;
}
bool Catalogo::adicionar(string categoria){
    if(quantidadeCategorias < tamanhoMaximo){
        for(int i = 0; i < quantidadeCategorias; i++){
            if (categorias[i] == categoria){
                return false;
            }
        }
        categorias[quantidadeCategorias] = categoria;
        quantidadeCategorias++;
        return true;
    }
    return false;
}

int Catalogo::getDuracaoTotal(){
    int duracaoTotal = 0;
    for (int i = 0; i < quantidadeFilmes; i++)
        duracaoTotal += filmes[i]->getDuracao();
    return duracaoTotal;
}

int Catalogo::getTotalDeVisualizacoes(){
    int visualizacoes = 0;
    for (int i = 0; i < quantidadeFilmes; i++)
        visualizacoes += filmes[i]->getVisualizacoes();
    return visualizacoes;
}

Filme** Catalogo::getFilmes(){
    return filmes;
}

string* Catalogo::getCategorias(){
    return categorias;
}

Lancamento** Catalogo::getLancamentos(int &quantidadedeLancamentos){
    Lancamento** l = new Lancamento*[tamanhoMaximo];
    quantidadedeLancamentos = 0;
    for (int i = 0; i < quantidadeFilmes; i++){
        if (dynamic_cast<Lancamento*>(filmes[i]) != NULL){
            l[quantidadedeLancamentos] = dynamic_cast<Lancamento*>(filmes[i]);
            quantidadedeLancamentos++;
        }
    }
    if (quantidadedeLancamentos == 0){
        return NULL;
    }else{
        return l;
    }
}
void Catalogo::imprimir(){
    cout << "Catalogo: " << quantidadeFilmes << " filmes e " << quantidadeCategorias << " categorias"<<endl;
    for(int i = 0; i < quantidadeFilmes; i++){
        filmes[i]->imprimir();
    }
}