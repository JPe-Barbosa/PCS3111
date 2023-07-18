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
        virtual int getValor(int registrador);
        virtual void setValor(int registrador, int valor);
        virtual void imprimir(); 
};

#endif