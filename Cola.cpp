#include "Cola.h"

Cola::Cola(void){
    ini = NULL;
    fin = NULL;
}
Cola::~Cola(void){
    vaciaCola();
}
void Cola::push(int d){
}
int Cola::pop(void){
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
