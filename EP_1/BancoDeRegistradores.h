#ifndef BANCODEREGISTRADORES_H
#define BANCODEREGISTRADORES_H
#define QUANTIDADE_REGISTRADORES 32
using namespace std;

class BancoDeRegistradores {
    private:
        int registradores[QUANTIDADE_REGISTRADORES];
    public:
        BancoDeRegistradores();
        virtual ~BancoDeRegistradores();
        int getValor(int registrador);
        void setValor(int registrador, int valor);
        void imprimir();
};

#endif