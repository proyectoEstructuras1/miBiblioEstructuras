#include "Libro.h"

Libro::Libro(void){
}
Libro::Libro(string T, string A, string E){
    Titulo = T;
    Autor = A;
    Editorial = E;
}
void Libro::pideDatos(void){
    cout<<"Ingresa Titulo ";
    getline(cin,Titulo,'\n');
    cout<<"Ingresa Autor ";
    getline(cin,Autor,'\n');
    cout<<"Ingresa Editorial ";
    getline(cin,Editorial,'\n');
}
void Libro::muestraDatos(void){
    cout<<"Titulo: "<<Titulo<<endl
        <<"Autor: "<<Autor<<endl
        <<"Editorial: "<<Editorial<<endl;
}
string Libro::dameTitulo(void){
    return Titulo;
}
void Libro::modificaTitulo(string T){
    Titulo = T;
}
string Libro::dameAutor(void){
    return Autor;
}
void Libro::modificaAutor(string A){
    Autor = A;
}
string Libro::dameEditorial(void){
    return Editorial;
}
void Libro::modificaEditorial(string E){
    Editorial = E;
}
istream& operator>>(istream& teclado, Libro& X){
    X.pideDatos();
    return teclado;
}
ostream& operator<<(ostream& monitor, Libro X){
    X.muestraDatos();
    return monitor;
}
bool operator==(Libro Izquierdo, Libro Derecho){
    return
            Izquierdo.dameAutor() == Derecho.dameAutor()
            &&
            Izquierdo.dameTitulo() == Derecho.dameTitulo()
            &&
            Izquierdo.dameEditorial() == Derecho.dameEditorial()
    ;
}
bool operator!=(Libro Izquierdo, Libro Derecho){
    return
            Izquierdo.dameAutor() != Derecho.dameAutor()
            ||
            Izquierdo.dameTitulo() != Derecho.dameTitulo()
            ||
            Izquierdo.dameEditorial() != Derecho.dameEditorial()
    ;
}

