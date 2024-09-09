#include <iostream>
#include "Cola/Cola.h"
#include "Pila/Pila.h"
using namespace std;

void separar(Cola<int> &cola, Pila<int> &pila){
    Cola<int> aux;
    while(!cola.esVacia()){
        if(cola.peek()%2!=0){
            pila.push(cola.desencolar());
        }else{
            aux.encolar(cola.desencolar());
        }
    }
    while(!aux.esVacia()){
        cola.encolar(aux.desencolar());
    }
}

int main(){
    Cola<int> cola;
    Pila<int> pila;
    cola.encolar(1);
    cola.encolar(3);
    cola.encolar(2);
    cola.encolar(4);
    cola.encolar(5);
    cola.encolar(8);
    separar(cola, pila);
    if (cola.esVacia()){
        cout<<"Cola vacia"<<endl;
    }
    cout<<"Cola modificada: ";
    while(!cola.esVacia()){
        cout<<cola.desencolar()<<" ";
    }
    cout<<endl;
    cout<<"Pila: "<<endl;
    while(!pila.esVacia()){
    cout << pila.pop() << endl;  // Imprime cada elemento en una nueva línea
    }
    return 0;
}