#include <iostream>
#include <string>

using namespace std;

/**
 * 1. Clase Nodo (DiaNode)
 * Representa cada elemento (un día) en nuestra lista.
 * Contiene los punteros 'next' (siguiente) y 'prev' (anterior).
 */
class DiaNode {
public:
    string nombreDia;
    bool esLaborable; // true = día de trabajo, false = feriado o fin de semana
    DiaNode* next;
    DiaNode* prev;

    // Constructor del Nodo
    DiaNode(string nombre, bool laborable)
        : nombreDia(nombre), esLaborable(laborable), next(nullptr), prev(nullptr) {}
};

/**
 * 2. Clase de la Lista (ListaCircularDoble)
 * Administra la lista completa. Sabe cómo insertar, mostrar
 * y realizar operaciones en los nodos.
 */
class ListaCircularDoble {
private:
    DiaNode* head; // Un punto de entrada a la lista.

public:
    // Constructor: Inicializa la lista como vacía
    ListaCircularDoble() : head(nullptr) {}

    // Destructor: Libera toda la memoria
    ~ListaCircularDoble() {
        if (head == nullptr) {
            return;
        }

        DiaNode* current = head;
        DiaNode* last = head->prev; // Obtenemos el último nodo

        // Rompemos el círculo para tratarla como una lista simple
        last->next = nullptr; 

        while (current != nullptr) {
            DiaNode* temp = current;
            current = current->next;
            cout << "\n[Debug] Liberando memoria de: " << temp->nombreDia;
            delete temp;
        }
        cout << "\nMemoria liberada." << endl;
    }

    /**
     * Inserta un nuevo día al final de la lista circular.
     */
    void insertarDia(string nombre, bool laborable) {
        DiaNode* newNode = new DiaNode(nombre, laborable);

        if (head == nullptr) {
            // Caso 1: La lista está vacía
            head = newNode;
            newNode->next = head; // Apunta a sí mismo
            newNode->prev = head; // Apunta a sí mismo
        } else {
            // Caso 2: La lista ya tiene nodos
            DiaNode* last = head->prev; // Encontramos el último nodo actual

            last->next = newNode;   // El último apunta al nuevo
            newNode->prev = last;   // El nuevo apunta al último
            newNode->next = head;   // El nuevo apunta al inicio (head)
            head->prev = newNode;   // El inicio (head) apunta al nuevo
        }
    }

    /**
     * Muestra todos los días en la lista circular.
     */
    void mostrarDias() {
        if (head == nullptr) {
            cout << "La semana (lista) está vacía." << endl;
            return;
        }

        DiaNode* temp = head;
        cout << "--- Mostrando Semana (Lista Circular) ---" << endl;
        do {
            cout << "[ " << temp->nombreDia 
                 << (temp->esLaborable ? " (Laborable)" : " (FERIADO)") 
                 << " ] <-> ";
            temp = temp->next;
        } while (temp != head); // Termina cuando damos la vuelta completa
        cout << "(vuelve a " << head->nombreDia << ")" << endl;
    }

    /**
     * Resuelve el problema: Encuentra el siguiente día laborable.
     */
    void encontrarSiguienteLaborable(string diaActual) {
        if (head == nullptr) {
            cout << "La lista está vacía." << endl;
            return;
        }

        // 1. Buscar el nodo del día actual
        DiaNode* nodoActual = head;
        bool encontrado = false;
        do {
            if (nodoActual->nombreDia == diaActual) {
                encontrado = true;
                break;
            }
            nodoActual = nodoActual->next;
        } while (nodoActual != head);

        if (!encontrado) {
            cout << "Error: El día '" << diaActual << "' no existe en la lista." << endl;
            return;
        }

        // 2. Buscar el siguiente día laborable
        cout << "\n--- Buscando siguiente laborable desde: " << diaActual << " ---" << endl;
        DiaNode* siguiente = nodoActual->next; // Empezamos a buscar desde el DÍA SIGUIENTE

        // Damos un límite de 14 vueltas para evitar un bucle infinito
        // si por error ningún día es laborable.
        for (int i = 0; i < 14; i++) {
            if (siguiente->esLaborable) {
                cout << "==> El siguiente día laborable es: " << siguiente->nombreDia << endl;
                return; // ¡Encontrado!
            }
            // Si no es laborable, avanzamos al siguiente
            cout << "  - " << siguiente->nombreDia << " no es laborable. Revisando el siguiente..." << endl;
            siguiente = siguiente->next;
        }

        cout << "No se encontró ningún día laborable en la lista." << endl;
    }
};

/**
 * 3. Función Principal (main)
 * Aquí creamos la lista y probamos la funcionalidad.
 */
int main() {
    // Creamos la "semana"
    ListaCircularDoble semana;

    semana.insertarDia("Lunes", true);
    semana.insertarDia("Martes", true);
    semana.insertarDia("Miércoles", true);
    semana.insertarDia("Jueves", true);
    
    // Simulamos el feriado que mencionan en la imagen (ej. el 31 fue viernes)
    semana.insertarDia("Viernes", false); // ¡FERIADO!
    
    semana.insertarDia("Sábado", false); // Fin de semana
    semana.insertarDia("Domingo", false); // Fin de semana

    // Mostramos la lista completa
    semana.mostrarDias();

    // --- Pruebas del problema ---

    // Prueba 1: Empezar desde un día normal
    // Si hoy es Miércoles, el siguiente laborable es Jueves.
    semana.encontrarSiguienteLaborable("Miércoles");

    // Prueba 2: Empezar justo antes del feriado
    // Si hoy es Jueves, el siguiente es Viernes (feriado),
    // Sábado (no), Domingo (no)... el siguiente es Lunes.
    semana.encontrarSiguienteLaborable("Jueves");

    // Prueba 3: Empezar en fin de semana
    // Si hoy es Sábado, el siguiente es Domingo (no)...
    // el siguiente es Lunes.
    semana.encontrarSiguienteLaborable("Sábado");

    return 0; // El destructor se llamará aquí y liberará la memoria
}