#pragma once

struct Nodo {
    int dato;
    Nodo *next;
};

class Lista {
public: 
    Nodo *head;

public:
    Lista();

    ~Lista();

    void insertarPorCabeza(int valor);
    void insertarPorCola(int valor);
    void mostrar();
};

