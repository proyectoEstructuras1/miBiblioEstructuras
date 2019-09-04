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
bool Cola::estaVacia(void){
    return (ini == NULL && fin == ini);
}
void Cola::vaciaCola(void){
    while(!estaVacia())
        cout<<pop()<<endl;
}
