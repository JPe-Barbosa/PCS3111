#include "Item.h"
#include <string>

using namespace std;
 
Item::Item(string nome, int duracao):nome(nome),duracao(duracao),id(getProximoId()){
Item::IDs++;
}

Item::~Item(){}

int Item::IDs = 0;

string Item::getNome() {
    return this->nome;
}

int Item::getDuracao() {
    return this->duracao;
}

int Item::getId(){
    return id;
}

int Item::getProximoId(){
    return Item::IDs;
}