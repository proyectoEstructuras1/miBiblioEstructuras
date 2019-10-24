#ifndef CONTACTO_H
#define CONTACTO_H

#include <iostream>
#include <string>
using namespace std;
class Contacto{
private:
    string Nombre;
    string EMail;
    string Telefono;
public:
    Contacto(void);
    Contacto(string N, string EM, string T);
    void pideDatos(void);
    void muestraDatos(void);
    string dameNombre(void);
    void modificaNombre(string N);
    string dameEMail(void);
    void modificaEMail(string EM);
    string dameTelefono(void);
    void modificaTelefono(string T);
};
istream& operator>>(istream& teclado, Contacto& X);
ostream& operator<<(ostream& monitor, Contacto X);
bool operator==(Contacto Izquierdo, Contacto Derecho);
bool operator!=(Contacto Izquierdo, Contacto Derecho);

#endif // CONTACTO_H
