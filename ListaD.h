#ifndef LISTAD_H
#define LISTAD_H

#include <iostream>
#include "NodoD.h"
using namespace std;
class ListaD{
private:
    NodoD* ini;
    NodoD* fin;
public:
    ListaD(void);
    ~ListaD(void);
};

#endif // LISTAD_H
