#include <iostream>
#include "Cola/Cola.h"
using namespace std;

int superposicion(Cola<int> &cola, int n){
    Cola <int> aux;
    int suma=0;
    while(!cola.esVacia()&&cola.peek()!=n){
        suma+=cola.desencolar();
    }
    return suma;
}

int main(){
    Cola<int> cola;
    int n=1;
    while(n>0){
        cin>>n;
        cola.encolar(n);
    }
    cout<<superposicion(cola, 5);

    return 0;
}