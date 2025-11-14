#include <iostream>
#include "Lista.hpp" 
#include "Validacion.hpp"  

using namespace std;

  void separarDatosParesImpares (Lista& base, Lista& pares, Lista& impares) {
        Nodo* aux = base.head;
        while (aux != nullptr) {
            int valor = aux->dato;

            if (valor%2 == 0) {
                pares.insertarPorCola(valor);
            }
            else if (valor%2 == 1) {
                impares.insertarPorCola(valor);
            }
            aux = aux->next;
        }
    }

int main() {
    Lista lista; 
    int valor = 0;

    cout<<"Escriba un numero entero positivo."<<endl;
    cout<<"(Escriba 0 para terminar de ingresar datos)"<<endl;
    while(true) {
        cout << "Numero: ";
        valor = ingresarEntero();
        
        if (valor == 0) {
            break;
        } else lista.insertarPorCola(valor);
    }

    cout<<"Lista Base:"<<endl;
    lista.mostrar();

    Lista pares, impares;
    separarDatosParesImpares(lista, pares, impares);

    cout<<"Lista Par:"<<endl;
    pares.mostrar();

    cout<<"Lista Impar"<<endl;
    impares.mostrar();
    
    return 0;
}