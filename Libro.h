#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <string>
using namespace std;
class Libro{
private:
    string Titulo;
    string Autor;
    string Editorial;
public:
    Libro(void);
    Libro(string T, string A, string E);
    void pideDatos(void);
    void muestraDatos(void);
    string dameTitulo(void);
    void modificaTitulo(string T);
    string dameAutor(void);
    void modificaAutor(string A);
    string dameEditorial(void);
    void modificaEditorial(string E);
};
istream& operator>>(istream& teclado, Libro& X);
ostream& operator<<(ostream& monitor, Libro X);
bool operator==(Libro Izquierdo, Libro Derecho);
bool operator!=(Libro Izquierdo, Libro Derecho);

#endif // LIBRO_H
