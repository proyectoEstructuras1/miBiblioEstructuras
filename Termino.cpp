#include "Termino.h"

Termino::Termino(void){
    coeficiente = 0.0;
    exponente = 0;
}
Termino::Termino(float c, int e){
    coeficiente = c;
    exponente = e;
}
void Termino::pideDatos(void){
    cout<<"Dame coeficiente ";cin>>coeficiente;
    cout<<"Dame exponente ";cin>>exponente;
}
void Termino::muestraDatos(void){
    if(coeficiente!=0){
        if(coeficiente == -1){
            if(exponente==0)
                cout<<coeficiente;
            else if(exponente == 1)
                cout<<"-x";
            else
                cout<<"-x^"<<exponente;
        }
        else if(coeficiente == 1){
            if(exponente==0)
                cout<<coeficiente;
            else if(exponente == 1)
                cout<<"x";
            else
                cout<<"x^"<<exponente;
        }
        else{
            if(exponente==0)
                cout<<coeficiente;
            else if(exponente == 1)
                cout<<coeficiente<<"x";
            else
            cout<<coeficiente<<"x^"<<exponente;
        }
    }
}
float Termino::dameCoeficiente(void){
    return coeficiente;
}
void Termino::modificaCoeficiente(float c){
    coeficiente = c;
}
int Termino::dameExponente(void){
    return exponente;
}
void Termino::modificaExponente(int e){
    exponente = e;
}
istream& operator>>(istream& teclado, Termino& Derecho){
    Derecho.pideDatos();
    return teclado;
}
ostream& operator<<(ostream& monitor, Termino Derecho){
    Derecho.muestraDatos();
    return monitor;
}
