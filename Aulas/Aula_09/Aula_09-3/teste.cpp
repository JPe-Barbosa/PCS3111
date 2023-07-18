#include "Filme.h"
#include "Catalogo.h"
#include "SemVisualizacoes.h"
#include "Plano.h"
#include <iostream>
#include <stdexcept>

using namespace std;
void teste1(){
    try{
    Filme* f1 = new Filme("a",-1); 
    }catch(invalid_argument *e){
        cout << e->what()<< endl;
        delete e;
    }
    Filme* f2 = new Filme("Matrix",136);
    try{
    f2->assistir(-1); 
    }catch(invalid_argument *e){
        cout << e->what()<< endl;
        delete e;
    }
    try{
    f2->assistir(137); 
    }catch(invalid_argument *e){
        cout << e->what()<< endl;
        delete e;
    }
    delete f2;
}

void teste2(){
    Filme* f1 = new Filme("Matrix",136);   
    Filme* f2 = new Filme("Smurfs",100);
    Catalogo* c1 = new Catalogo(2);
    c1->adicionar(f1);
    c1->adicionar(f2);

    try{
        c1->getFilmeMaisVisto();
    }catch(SemVisualizacoes *e){
        cout << e->what()<< endl;
        delete e;
    }
}

void teste3(){
    Plano* p1 = new Plano(2);
    Catalogo* c1 = new Catalogo(2);
    Catalogo* c2 = new Catalogo(2);
    p1->adicionar(c1);
    p1->adicionar(c2);
    Filme* f1 = new Filme("Matrix",136);   
    Filme* f2 = new Filme("Smurfs",100);
    Filme* f3 = new Filme("O Regresso",156);
    Filme* f4 = new Filme("Duna",160);
    c1->adicionar(f1);
    c1->adicionar(f2);
    c2->adicionar(f3);
    c2->adicionar(f4);
    p1->getDestaque();
    f1->assistir(135);
    f1->assistir(135);
    f1->assistir(135);
    f2->assistir(99);
    f3->assistir(155);
    f3->assistir(155);
    c1->getFilmeMaisVisto()->imprimir();
}
/*
int main(){
    teste3(); //Substitua pelo teste que deseja efetuar
    return 0;
}
*/


