#include "Catalogo.h"

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
    if(this->quantidade == 0) return NULL;
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

