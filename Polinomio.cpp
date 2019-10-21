#include "Polinomio.h"

Polinomio::Polinomio(void){
    ini = NULL;
}
Polinomio::~Polinomio(void){
    eliminaPolinomio();
}
bool Polinomio::estaVacio(void){
    return ini == NULL;
}
void Polinomio::muestraPolinomio(void){
    NodoP* aux=ini;
    while(aux!=NULL){
        if(aux!=ini && aux->dameDato().dameCoeficiente() > 0)
            cout<<"+";
        cout<<aux->dameDato();

        aux = aux->dameSig();
        cout<<" ";
    }
}
void Polinomio::eliminaPolinomio(void){
    NodoP* aux=ini;
    while(ini!=NULL){
        ini = ini->dameSig();
        delete aux;
        aux = ini;
    }
}
void Polinomio::insertaTermino(Termino A){
    if(A.dameCoeficiente()!=0){ //Solo inserta terminos cuyo coeficiente sea diferente de cero.

        if(estaVacio() || A.dameExponente() > ini->dameDato().dameExponente())//Si esta vacio el polinomio o el exponente del termino a insertar es mayor al exponente del termino en ini
            ini = new NodoP(A, ini);
        else if(A.dameExponente() == ini->dameDato().dameExponente()){//Si el termino a insertar y el primer termino tienen el mismo exponente
            A.modificaCoeficiente(A.dameCoeficiente() + ini->dameDato().dameCoeficiente());
            ini->modificaDato(A);
        }
        else{
            //Continua tu tarea...
        }
    }
}
void Polinomio::insertaTermino(float c, int e){
    Termino A(c,e);
    insertaTermino(A);
}
bool Polinomio::eliminaTermino(Termino A){
    return false;
}
bool Polinomio::eliminaTermino(float c, int e){
    Termino A(c,e);
    return eliminaTermino(A);
}
void Polinomio::guardaPolinomio(void){
    ofstream HaciaArchivo("polinomio.txt");
    NodoP* aux=ini;
    while(aux != NULL){
        HaciaArchivo
                << aux->dameDato().dameCoeficiente() << ","
                << aux->dameDato().dameExponente();
        aux = aux->dameSig();
        if(aux != NULL)
            HaciaArchivo << endl;
    }
    HaciaArchivo.close();
}
void Polinomio::cargaPolinomio(void){
    ifstream DesdeArchivo("polinomio.txt");
    float c;
    int e;
    char coma;
    while(!DesdeArchivo.eof()){
        DesdeArchivo >> c  >> coma >> e;
        insertaTermino(c,e);
    }
    DesdeArchivo.close();
}

