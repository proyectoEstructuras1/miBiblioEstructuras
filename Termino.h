#ifndef TERMINO_H
#define TERMINO_H

#include <iostream>
using namespace std;

class Termino{
private:
    float coeficiente;
    int exponente;
public:
    Termino(void);
    Termino(float c, int e);
    void pideDatos(void);
    void muestraDatos(void);
    float dameCoeficiente(void);
    void modificaCoeficiente(float c);
    int dameExponente(void);
    void modificaExponente(int e);
};
istream& operator>>(istream& teclado, Termino& Derecho);
ostream& operator<<(ostream& monitor, Termino Derecho);

#endif // TERMINO_H
