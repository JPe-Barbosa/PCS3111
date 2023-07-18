#ifndef DADO
#define DADO
class Dado{
    public:
    Dado(int valor);
    virtual ~Dado();
    virtual int getValor();
    virtual void imprimir();
     
    private:
    int valor;
};
#endif 