#ifndef LISTAL_H
#define LISTAL_H

#include <iostream>
#include <stdlib.h>
#include "NodoL.h"
using namespace std;
class ListaL{
private:
    NodoL* ini;
public:
    ListaL(void);
    ~ListaL(void);
    bool estaVacia(void);
    void insertaNodo(Libro d);
    bool buscaNodo(Libro d);
    void eliminaListaL(void);
    void muestraListaL(void);
};

#endif // LISTAL_H
