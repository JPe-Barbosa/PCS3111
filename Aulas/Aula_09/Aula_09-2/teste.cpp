#include "Filme.h"
#include "Catalogo.h"
#include "SemVisualizacoes.h"
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
        cout << c1->getFilmeMaisVisto()->getNome();
    }catch(SemVisualizacoes *e){
        cout << e->what()<< endl;
        delete e;
    }
    
}

void teste3(){
    /*Implemente conforme o enunciado*/
}
/*
int main(){
    teste2(); //Substitua pelo teste que deseja efetuar
    return 0;
}
*/


