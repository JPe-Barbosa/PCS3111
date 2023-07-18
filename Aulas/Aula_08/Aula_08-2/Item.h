#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
    protected:
        string nome;
        int duracao;
        int id;
        static int IDs;

    public:
        Item(string nome, int duracao);
        virtual ~Item();
        int getId();
        static int getProximoId();
        string getNome();
        int getDuracao();
        virtual void imprimir() = 0;
    
};

#endif  // ITEM_H