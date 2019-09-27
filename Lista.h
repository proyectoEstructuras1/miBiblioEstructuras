#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <stdlib.h>
#include "Nodo.h"
using namespace std;
class Lista{
private:
    Nodo* ini;
public:
    Lista(void);
    ~Lista(void);
    void eliminaLista(void);
    bool estaVacia(void);
    void insertaNodo(int d);
    bool eliminaNodo(int d);
    int eliminaPrimero(void);
    int eliminaUltimo(void);
    bool buscaNodo(int d);
    void muestraLista(void);
    int dameDatoIni(void);
    int dameDatoFin(void);
    void invierteNodos(int n1, int n2);
    void generaLista(int n);
};

#endif // LISTA_H















