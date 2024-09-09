#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void suprimir(Cola<int> &cola, int n){
    Cola<int> aux;
    while (!cola.esVacia()) {
        if (cola.peek() <= n) {
            aux.encolar(cola.desencolar());
        } else {
            cola.desencolar();
        }
    }
    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }
}

int main() {
    cout << "Ejercicio N° 2" << endl;
    Cola<int> cola;
    int n;
    cola.encolar(1);
    cola.encolar(2);
    cola.encolar(3);
    cola.encolar(4);
    cola.encolar(5);
    cout << "Ingrese el numero a suprimir: ";
    cin >> n;
    suprimir(cola, n);
    cout << "Cola modificada: ";
    while (!cola.esVacia()) {
        cout << cola.desencolar() << " ";
    }
    return 0;
}
