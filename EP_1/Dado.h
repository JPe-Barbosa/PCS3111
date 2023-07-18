#ifndef DADO_H
#define DADO_H

using namespace std;

class Dado {
    private:
        int valor;
    public:
        Dado(int valor);
        virtual ~Dado();
        int getValor();
        void imprimir();
};

#endif