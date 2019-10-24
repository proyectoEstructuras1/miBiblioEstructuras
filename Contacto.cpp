#include "Contacto.h"

Contacto::Contacto(void){
}
Contacto::Contacto(string N, string EM, string T){
    Nombre = N;
    EMail = EM;
    Telefono = T;
}
void Contacto::pideDatos(void){
    cout<<"Ingresa Nombre ";
    getline(cin,Nombre,'\n');
    cout<<"Ingresa EMail ";
    getline(cin,EMail,'\n');
    cout<<"Ingresa Telefono ";
    getline(cin,Telefono,'\n');
}
void Contacto::muestraDatos(void){
    cout<<"Nombre: "<<Nombre<<endl
        <<"EMail: "<<EMail<<endl
        <<"Telefono: "<<Telefono<<endl;
}
string Contacto::dameNombre(void){
    return Nombre;
}
void Contacto::modificaNombre(string N){
    Nombre = N;
}
string Contacto::dameEMail(void){
    return EMail;
}
void Contacto::modificaEMail(string EM){
    EMail = EM;
}
string Contacto::dameTelefono(void){
    return Telefono;
}
void Contacto::modificaTelefono(string T){
    Telefono = T;
}
istream& operator>>(istream& teclado, Contacto& X){
    X.pideDatos();
    return teclado;
}
ostream& operator<<(ostream& monitor, Contacto X){
    X.muestraDatos();
    return monitor;
}
bool operator==(Contacto Izquierdo, Contacto Derecho){
    return
            Izquierdo.dameNombre() == Derecho.dameNombre()
            &&
            Izquierdo.dameEMail() == Derecho.dameEMail()
            &&
            Izquierdo.dameTelefono() == Derecho.dameTelefono()
    ;
}
bool operator!=(Contacto Izquierdo, Contacto Derecho){
    return
            Izquierdo.dameNombre() != Derecho.dameNombre()
            ||
            Izquierdo.dameEMail() != Derecho.dameEMail()
            ||
            Izquierdo.dameTelefono() != Derecho.dameTelefono()
    ;
}
ofstream& operator<<(ofstream& HaciaArchivo, Contacto Derecho){
    HaciaArchivo<<Derecho.dameNombre()<<","
                <<Derecho.dameEMail()<<","
                <<Derecho.dameTelefono();
    return HaciaArchivo;
}
ifstream& operator>>(ifstream& DesdeArchivo, Contacto& Derecho){
    string datos,atributo;
    getline(DesdeArchivo,datos);
    stringstream ss(datos);
    getline(ss,atributo,',');
    Derecho.modificaNombre(atributo);
    getline(ss,atributo,',');
    Derecho.modificaEMail(atributo);
    getline(ss,atributo);
    Derecho.modificaTelefono(atributo);
    return DesdeArchivo;
}


