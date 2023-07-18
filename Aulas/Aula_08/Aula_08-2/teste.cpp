#include <iostream>

#include "Filme.h"
#include "Item.h"
#include "Serie.h"

void teste1() {
    Filme* F1 = new Filme("Luca", 95);
    F1->imprimir();
    Serie* S1 = new Serie("Modern Family", 5);
    for(int i = 0; i < 5; i++){
        S1->adicionar(new Episodio(to_string(i+1),30));
    }
    S1->imprimir();
    delete S1;
    delete F1;
}

void teste2() {
Filme* f1 = new Filme("Minari", 155);
Serie* s1 = new Serie("His Dark Materials", 5);
for(int i = 0; i < 5; i++){
    s1->adicionar(new Episodio(to_string(i+1),50));
}
cout << f1->getId() << endl;
cout << s1->getId() << endl;
cout << Item::getProximoId() << endl;
delete f1;
delete s1;
}

/*
int main() {
    teste2();
    return 0;
}
*/
