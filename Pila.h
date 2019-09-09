#ifndef PILA_H
#define PILA_H

#include <iostream>
#include "Nodo.h"
using namespace std;

class Pila{
private:
    Nodo* top;
public:
    Pila(void);
    ~Pila(void);
    void push(int d);
    int pop(void);
    int dameTop(void);
    void push(void);
    bool estaVacia(void);
    void vaciaPila(void);
};

#endif // PILA_H

