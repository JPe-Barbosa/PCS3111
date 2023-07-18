#include"Filme.h"
#include"PersistenciaDeFilme.h"
#include <stdexcept>
#include <iostream>

using namespace std;

void teste1() {
    Filme* f1 = new Filme("Luca", 95);
    Filme* f2 = new Filme("Tenet", 150);
    f2->assistir(150);
    f2->assistir(150);
    f2->assistir(150);
    f2->assistir(150);
    f2->assistir(150);
    f2->assistir(150);
    f2->assistir(150);
    PersistenciaDeFilme* p1 = new PersistenciaDeFilme("teste1.txt");
    p1->inserir(f1);
    p1->inserir(f2);
    delete f1;
    delete f2;
    delete p1;
}

void teste2() {
    PersistenciaDeFilme* p1 = new PersistenciaDeFilme("teste2.txt");
    try{
        Catalogo* c1 = p1->obter();
        if(c1 != NULL){
            c1->imprimir();
        }
        delete c1;
    }catch(invalid_argument *e){
        cout << e->what();
    }

}

/*
int main() {
    teste2();
    return 0;
}
*/