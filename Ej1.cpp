#include <iostream>
#include "Cola/Cola.h"
using namespace std;

int tama(Cola<char> &cola) {
    int tam = 0;
    Cola<char> aux;
    while (!cola.esVacia()) {
        aux.encolar(cola.desencolar());
        tam++;
    }
    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }
    return tam;
}

bool comparar(Cola<char> &cola1, Cola<char> &cola2) {
    int tam1 = tama(cola1);  // Guardamos el tamaño de la primera cola
    int tam2 = tama(cola2);  // Guardamos el tamaño de la segunda cola

    if (tam1 == tam2) {
        Cola<char> aux1, aux2;
        for (int i = 0; i < tam1; i++) {
            char elem1 = cola1.desencolar();
            char elem2 = cola2.desencolar();

            if (elem1 != elem2) {
                return false;  // Si algún elemento no coincide, devolvemos false
            }

            aux1.encolar(elem1);
            aux2.encolar(elem2);
        }

        // Restaurar las colas originales
        while (!aux1.esVacia()) {
            cola1.encolar(aux1.desencolar());
        }
        while (!aux2.esVacia()) {
            cola2.encolar(aux2.desencolar());
        }

        return true;  // Si se compararon todos los elementos y son iguales
    }

    return false;  // Si los tamaños no coinciden, devolvemos false
}

int main() {
    Cola<char> cola1;
    Cola<char> cola2;

    cout << "Ejercicio N° 1" << endl;

    cola1.encolar('a');
    cola1.encolar('b');
    cola1.encolar('c');
    cola1.encolar('d');

    cola2.encolar('a');
    cola2.encolar('b');
    cola2.encolar('c');
    cola2.encolar('e');

    if (comparar(cola1, cola2)) {
        cout << "Las colas son iguales" << endl;
    } else {
        cout << "Las colas son distintas" << endl;
    }

    return 0;
}