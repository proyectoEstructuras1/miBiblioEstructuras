#ifndef LISTAC_H
#define LISTAC_H

#include <iostream>
#include <stdlib.h>
#include "NodoC.h"
using namespace std;
class ListaC{
private:
    NodoC* ini;
public:
    ListaC(void);
    ~ListaC(void);
    bool estaVacia(void);
    void insertaNodo(Contacto d);
    bool buscaNodo(Contacto d);
    void eliminaListaC(void);
    void muestraListaC(void);
};

#endif // LISTAC_H
