#include <iostream>
#include <string>
using namespace std;

class Filme {
public:

    void assistir(int tempo);

    void imprimir();

    string nome;
    int duracao;
    int visualizacoes = 0;
};

void Filme::assistir(int tempo){
    if (((double)this->duracao)*0.7 <= tempo){
        this->visualizacoes += 1;
    }
}

void Filme::imprimir(){
    cout <<"Filme: "<< this->nome <<" - " << this->duracao << " minutos - " << this->visualizacoes << " visualizacoes" << endl;
}

class Catalogo {
public:

    int getDuracaoTotal();
    int getTotalDeVisualizacoes();
    bool adicionar(Filme* f);

    Filme* f1 = NULL;
    Filme* f2 = NULL;
    int quantidade = 0;
};

int Catalogo :: getDuracaoTotal() {
    switch(this->quantidade){
        case 0:
            return 0;
        case 1: 
            return f1->duracao;
        case 2:
            return f1->duracao + f2->duracao;
        default:
            return 0;
    }
}

int Catalogo::getTotalDeVisualizacoes(){
    switch(this->quantidade){
        case 0:
            return 0;
        case 1: 
            return f1->visualizacoes;
        case 2:
            return f1->visualizacoes + f2->visualizacoes;
        default:
            return 0;
    }
}

bool Catalogo::adicionar(Filme* f){
    if(this->quantidade == 1 && f == f1){
        return false;
    }
    switch (this->quantidade){
        case 0:
            f1 = f;
            this->quantidade += 1;
        break;
        case 1:
            f2 = f;
            this->quantidade += 1;
        break;
        default:
            return false;
        break;
    }
    return true;
}

void teste1() {
    Filme *MadMax = new Filme;
    MadMax->duracao = 120;
    MadMax->nome = "MadMax";

    MadMax->assistir(100);
    MadMax->assistir(87);
    MadMax->imprimir();
}

void teste2() {
    Filme *MadMax = new Filme;
    MadMax->duracao = 120;
    MadMax->nome = "MadMax";

    MadMax->assistir(100);
    MadMax->assistir(87);
    MadMax->imprimir();

    Filme *Mercenarios = new Filme;
    Mercenarios->duracao = 103;
    Mercenarios->nome = "Mercenarios";

    Mercenarios->assistir(103);
    Mercenarios->assistir(90);
    Mercenarios->assistir(98);
    
    Mercenarios->imprimir();

    Catalogo *Catalogo1 = new Catalogo;
    Catalogo1->adicionar(MadMax);
    Catalogo1->adicionar(Mercenarios);

    cout << "Duracao: " << Catalogo1->getDuracaoTotal() << endl;
    cout << "total de visualizacoes: " << Catalogo1->getTotalDeVisualizacoes() << endl;
}

/*
int main(){
    teste2();
    return 0;
}
*/


