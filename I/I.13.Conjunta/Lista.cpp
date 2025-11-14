#include "Lista.hpp"       // Incluimos nuestra propia cabecera
#include <iostream>      // Para usar cout y endl

using namespace std;

// Constructor: Inicializa la cabeza como nula
Lista::Lista() : head(nullptr) {}

// Destructor: Libera la memoria de todos los nodos
Lista::~Lista() {
    Nodo* actual = head;
    while (actual != nullptr) {
        Nodo* nodoAEliminar = actual;
        actual = actual->next;
        delete nodoAEliminar;
    }
}

// Implementación de los métodos
void Lista::insertarPorCabeza(int valor) {
    Nodo *nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->next = head;
    head = nuevo;
}

void Lista::insertarPorCola(int valor) {
    Nodo *nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->next = nullptr;

    if (head == nullptr) {
        head = nuevo;
    } else {
        Nodo *aux = head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = nuevo;
    }
}

void Lista::mostrar() {
    Nodo *aux = head;
    cout << "Lista: ";
    while (aux != nullptr) {
        cout << aux->dato << " -> ";
        aux = aux->next;
    }
    cout << "NULL" << endl;
}