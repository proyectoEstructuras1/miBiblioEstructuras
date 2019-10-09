#ifndef POLINOMIO_H
#define POLINOMIO_H


#include <iostream>
#include "NodoP.h"
using namespace std;
class Polinomio{
private:
    NodoP* ini;
public:
    Polinomio(void);
    ~Polinomio(void);
    bool estaVacio(void);
    void muestraPolinomio(void);
    void eliminaPolinomio(void);
    void insertaTermino(Termino A);
    void insertaTermino(float c, int e);
    bool eliminaTermino(Termino A);
    bool eliminaTermino(float c, int e);
};

#endif // POLINOMIO_H
