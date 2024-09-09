#include <iostream>
#include <string>
#include "Cola/Cola.h"
using namespace std;

void menu(Cola<string> &cola){
    int opcion;
    string nombre;
    char continuar;
    do{
        cout<<"1. Agregar Documento"<<endl;
        cout<<"2. Mostrar cola"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1:
                cout<<"Ingrese el documento a imprimir: ";
                cin>>nombre;
                cola.encolar(nombre);
                break;
            case 2:
                if(cola.esVacia()){
                    cout<<"No hay documento para imprimir"<<endl;
                }else{
                    while (!cola.esVacia()) {
                        cout << "Imprimiendo: " << cola.desencolar() << endl;
                        if (!cola.esVacia()) {
                            cout << "¿Desea imprimir el siguiente documento? (s/n): ";
                            cin >> continuar;
                            if (continuar != 's') {
                                cout<<"Elementos en la cola: "<<cola.peek()<<" ";
                                Cola<string> aux;
                                while (!cola.esVacia()){
                                    aux.encolar(cola.desencolar());
                                }
                                while (!aux.esVacia()){
                                    cola.encolar(aux.desencolar());
                                }
                                
                                break;  // Detiene la impresión si el usuario no desea continuar
                            }
                        }
                    }
                }
                break;
            case 3:
                cout<<"Saliendo..."<<endl;
                break;
            default:
                cout<<"Opcion invalida"<<endl;
                break;
        }
    }while(opcion!=3);
}

int main(){
    Cola<string> cola;
    menu(cola);
    return 0;
}