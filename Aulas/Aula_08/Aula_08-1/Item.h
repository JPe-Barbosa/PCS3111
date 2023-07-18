#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
// Declare atributos e metodos comuns a qualquer Item

// Lembre-se que essa classe deve ser abstrata!
// Reveja o material da disciplina se tiver duvidas na
// sintaxe para declarar metodos abstratos
    protected:
        string nome;
        int duracao;
    public:
        Item(string nome, int duracao);
        virtual ~Item();
        string getNome();
        int getDuracao();
        virtual void imprimir() = 0;
    
};

#endif  // ITEM_H