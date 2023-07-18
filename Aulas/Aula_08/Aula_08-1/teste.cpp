#include "Filme.h"
#include "Item.h"
#include "Serie.h"

void teste1() {
    Filme* F1 = new Filme("Luca", 95);
    F1->imprimir();
    Serie* S1 = new Serie("Modern Family", 5);
    for(int i = 0; i < 5; i++){
        S1->adicionar(new Episodio("Episodio " + to_string(i+1),30));
    }
    S1->imprimir();
    delete S1;
    delete F1;
}

void teste2() {
    // Implemente o teste do exercicio 2
}

/*
int main() {
    teste1();
    return 0;
}
*/

