#include "Filme.h"
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
    /*Implemente conforme o enunciado*/
}

void teste3(){
    /*Implemente conforme o enunciado*/
}
/*
int main(){
    teste1(); //Substitua pelo teste que deseja efetuar
    return 0;
}

*/