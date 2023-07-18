#include "Plano.h"
#include <stdexcept>


using namespace std;

Plano::Plano(int quantidadeMaxima) : quantidadeMaxima(quantidadeMaxima), quantidade(0){
    catalogos = new Catalogo*[quantidadeMaxima];
}

Plano::~Plano(){
    delete[] catalogos;
}

int Plano::getQuantidadeMaxima() const {
    return this->quantidadeMaxima;
}

Catalogo** Plano::getCatalogos() const {
    return this->catalogos;
}

int Plano::getQuantidadeDeCatalogos() const {
    return this->quantidade;
}

void Plano::adicionar(Catalogo* c) {
    if (quantidade >= quantidadeMaxima)
        throw new overflow_error("catalogos estourou");
    if (c == NULL)
        throw new invalid_argument("nulo");

    for(int i = 0; i < quantidade; i++){
        if(c == catalogos[i])
            throw new invalid_argument("catalogo ja adicionado");
    }

    catalogos[quantidade++] = c;
}

Filme* Plano::getDestaque(){
    /*Implemente o metodo*/
    return NULL;
}
