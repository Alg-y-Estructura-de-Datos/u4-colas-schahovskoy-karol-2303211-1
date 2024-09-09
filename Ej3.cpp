#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void eliminar(Cola<int> &cola, int n) {
    Cola<int> aux;
    bool primerOcurrencia = false;
    
    while (!cola.esVacia()) {
        if (cola.peek() == n && !primerOcurrencia) {
            primerOcurrencia = true;
            aux.encolar(cola.desencolar());  // Mantenemos la primera ocurrencia
        } else if (cola.peek() == n && primerOcurrencia) {
            cola.desencolar();  // Eliminamos las ocurrencias adicionales
        } else {
            aux.encolar(cola.desencolar());  // Encolamos los elementos que no son 'n'
            
        }
    }

    // Restaurar la cola original desde la auxiliar
    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }

    if (!primerOcurrencia){
        cout<<"El numero no se encuentra en la cola"<<endl;
    }
}

int main() {
    cout << "Ejercicio N° 3" << endl;
    Cola<int> cola;
    cola.encolar(1);
    cola.encolar(2);
    cola.encolar(3);
    cola.encolar(4);
    cola.encolar(3);  // Agregamos una ocurrencia adicional para probar
    cola.encolar(5);

    int n;
    cout << "Ingrese el numero a eliminar: ";
    cin >> n;

    eliminar(cola, n);

    cout << "Cola: ";
    while (!cola.esVacia()) {
        cout << cola.desencolar() << " ";
    }

    return 0;
}