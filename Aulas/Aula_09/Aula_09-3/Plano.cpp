#include "Plano.h"
#include "SemVisualizacoes.h"
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
    int entrou = 0,entrou2 = 0;
    Filme* maisvisto = new Filme("",1);
    if(quantidade == 0){return NULL;}
    for(int i =0; i < this->quantidade; i++){
        try{
            this->catalogos[i]->getFilmeMaisVisto();
        }catch(SemVisualizacoes *e){
            entrou = 1;
            delete e;
        }
        if (entrou == 1){
            entrou = 0;
        }else{
            entrou2 = 1;
            if(maisvisto->getVisualizacoes() < this->catalogos[i]->getFilmeMaisVisto()->getVisualizacoes()){
                maisvisto = this->catalogos[i]->getFilmeMaisVisto();
            }
        }
    }
    if (entrou2 == 0){
        return NULL;
    }else{
        return maisvisto;
    }
}
