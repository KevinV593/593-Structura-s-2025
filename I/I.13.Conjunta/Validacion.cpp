#include "Validacion.hpp"
#include <iostream>
#include <conio.h>
#include <cctype>
#include <cstdlib>
#include <string>

using namespace std;

int ingresarEntero() {
    string numero;
    bool valido = false;
    while (!valido) {
        
        char c;
        while (true) {
            c = _getch();

            if (c == '\r') {
                cout << endl;
                break;
            }
            else if (c == '\b') {
                if (!numero.empty()) {
                    numero.pop_back();
                    cout << "\b \b";
                }
            }
            else if (isdigit(c)) {
                numero += c;
                cout << c;
            }
        }

        if (numero.empty()) {
            cout << "\nEntrada no valida. No puede estar vacía." << endl;
        }
        else {
            valido = true;
        }
    }

    return atoi(numero.c_str());
}