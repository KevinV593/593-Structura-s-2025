#include <iostream>	
// Definimos la estructura de un nodo
struct Node {
    int data;          // Atributo entero
    Node* next;       // Atributo puntero al siguiente nodo
};

// Clase que representa la lista enlazada simple
class LinkedList {
public:
    Node* head; // Puntero al primer nodo de la lista

    LinkedList() {
        head = nullptr; // Inicializamos la lista como vacía
    }

    // Función para insertar un nodo al principio de la lista
    void insertAtHead(int value) {
        Node* newNode = new Node(); // Creamos un nuevo nodo
        newNode->data = value;       // Asignamos el valor
        newNode->next = head;        // El siguiente del nuevo nodo apunta a la cabeza actual
        head = newNode;              // La cabeza ahora es el nuevo nodo
    }

    // Función para insertar un nodo al final de la lista
    void insertAtTail(int value) {
        Node* newNode = new Node(); // Creamos un nuevo nodo
        newNode->data = value;       // Asignamos el valor
        newNode->next = nullptr;     // El siguiente del nuevo nodo es nullptr

        if (head == nullptr) { // Si la lista está vacía
            head = newNode;    // La cabeza es el nuevo nodo
            return;
        }

        // Si no está vacía, recorremos hasta el final
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next; // Vamos al siguiente nodo
        }
        temp->next = newNode; // El último nodo apunta al nuevo nodo
    }

    // Función para mostrar la lista
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> "; // Imprimimos el valor
            temp = temp->next; // Avanzamos al siguiente nodo
        }
        std::cout << "nullptr" << std::endl; // Fin de la lista
    }

    // Destructor para liberar memoria
    ~LinkedList() {
        Node* current = head;
        Node* nextNode;
        while (current != nullptr) {
            nextNode = current->next; // Guardamos el siguiente nodo
            delete current;            // Liberamos el nodo actual
            current = nextNode;       // Pasamos al siguiente
        }
    }
};

int main() {
    LinkedList list; // Creamos una instancia de la lista

    // Insertamos elementos en la lista
    list.insertAtHead(3);
    list.insertAtTail(5);
    list.insertAtHead(2);
    list.insertAtTail(7);

    // Mostramos la lista
    list.display();

    return 0; // Fin del programa
}
