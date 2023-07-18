#include "Catalogo.h"
#include "SemVisualizacoes.h"


Catalogo::Catalogo(int quantidadeMaxima)  : quantidadeMaxima(quantidadeMaxima), quantidade(0) {
    filmes = new Filme*[quantidadeMaxima];
}

Catalogo::~Catalogo()  {
    for(int i = 0; i < this->quantidade; ++i)
        delete this->filmes[i];

    delete[] this->filmes;
}

Filme** Catalogo::getFilmes() const  {
    return this->filmes;
}

int Catalogo::getQuantidadeFilmes() const  {
    return this->quantidade;
}

int Catalogo::getQuantidadeMaximaFilmes() const  {
    return this->quantidadeMaxima;
}

Filme* Catalogo::getFilmeMaisVisto(){
    int visualizaçoes = 0;
    if(this->quantidade == 0) throw new SemVisualizacoes("catalogo sem visualizacoes");
    for(int i = 0; i < this->quantidade; i++){
        if(this->filmes[i]->getVisualizacoes() != 0){
            visualizaçoes = 1;
        }
    }
    if(visualizaçoes == 0){
        throw new SemVisualizacoes("catalogo sem visualizacoes");
    }
    Filme* maisVisto = this->filmes[0];
    for(int i = 1; i < this->quantidade; i++){
        if(maisVisto->getVisualizacoes() < filmes[i]->getVisualizacoes()){
            maisVisto = filmes[i];
        }
    }
    return maisVisto;
}

bool Catalogo::adicionar(Filme* filme)  {
    if(this->quantidade >= this->quantidadeMaxima)
        return false;

    this->filmes[this->quantidade++] = filme;
    return true;
}

