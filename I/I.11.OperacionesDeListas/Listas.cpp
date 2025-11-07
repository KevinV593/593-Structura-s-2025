#include <iostream>
#include <functional>
using namespace std;

struct Nodo {
    int dato;
    Nodo *next;
};

class Lista {
public:
    Nodo *head;

public:
    Lista() : head(nullptr) {}

    void insertarPorCabeza(int valor) {
        Nodo *nuevo = new Nodo();
        nuevo->dato = valor;
        nuevo->next = head; 
        //suponiendo que en el main esta una instancia de un puntero tipo Node llamada lista = nullptr;
        head = nuevo;
        //Lista que ya no es nula apunta al nuevo nodo.
    }

    void insertarPorCola(int valor) {
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

    void mostrar() {
        Nodo *aux = head;
        cout << "Lista: ";
        while (aux != nullptr) {
            cout << aux->dato << " -> ";
            aux = aux->next;
        }
        cout << "NULL" << endl;
    }

    int multiplicacionDePosicionImpar() {
        int multiplicacion = 1;
        int posicion = 1;
        Nodo *actual = head;

        while (actual != nullptr) {
            if (posicion % 2 == 1) {
                multiplicacion *= actual->dato;
            }
            actual = actual->next;
            posicion++;
        }

        cout << "Producto de posiciones impares: " << multiplicacion << endl;
        return multiplicacion;
    }
};

// Función principal
int main() {
    Lista lista;

    lista.insertarPorCola(1);
    lista.insertarPorCabeza(0);
    lista.insertarPorCola(2);
    lista.insertarPorCola(3);
    lista.insertarPorCabeza(9);

    lista.mostrar();
    lista.multiplicacionDePosicionImpar();

    function<int(Nodo *&)> sumaParesRecursiva = [&](Nodo *&head) -> int {
        if (head == nullptr)
            return 0; // caso base
        if (head->dato % 2 == 0)
            return head->dato + sumaParesRecursiva(head->next);
        else
            return sumaParesRecursiva(head->next);
    };

    cout << "Suma de pares: " << sumaParesRecursiva(lista.head) << endl;

    return 0;
}