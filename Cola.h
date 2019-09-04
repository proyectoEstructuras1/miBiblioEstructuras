#ifndef COLA_H
#define COLA_H

#include <iostream>
#include "Nodo.h"
using namespace std;

class Cola{
private:
    Nodo* ini;
    Nodo* fin;
public:
    Cola(void);
    ~Cola(void);
    void push(int d);
    int pop(void);
    bool estaVacia(void);
    void vaciaCola(void);
};

#endif // COLA_H
