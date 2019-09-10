#include "Cola.h"

Cola::Cola(void){
    ini = NULL;
    fin = NULL;
}
Cola::~Cola(void){
    vaciaCola();
}
void Cola::push(int d){
    if(estaVacia()){
        ini = new Nodo(d, NULL);
        fin = ini;
    }
    else{
        fin ->modificaSig(new Nodo(d, NULL));
        fin = fin->dameSig();
    }
}
int Cola::pop(void){
    int d;
    Nodo* aux;
    d = ini->dameDato();
    aux = ini->dameSig();
    delete ini;
    ini = aux;
    if(ini == NULL)
        fin = ini;
    return d;
}
int Cola::dameIni(void){
    return ini->dameDato();
}
int Cola::dameFin(void){
    return fin->dameDato();
}
bool Cola::estaVacia(void){
    return (ini == NULL && fin == ini);
}
void Cola::vaciaCola(void){
    while(!estaVacia())
        cout<<pop()<<endl;
}
