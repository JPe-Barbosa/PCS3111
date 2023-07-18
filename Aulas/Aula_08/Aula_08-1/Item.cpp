#include "Item.h"
#include <string>

using namespace std;
 
Item::Item(string nome, int duracao):nome(nome),duracao(duracao){}

Item::~Item(){}

string Item::getNome() {
    return this->nome;
}

int Item::getDuracao() {
    return this->duracao;
}

// Faca os includes necessarios

// Faca a implementacao dos metodos concretos de Item