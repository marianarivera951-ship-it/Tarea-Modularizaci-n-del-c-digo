#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Producto {
    string codigo;
    string nombre;
    int cantidad;
};

int main() {
    vector<Producto> inventario;
    int opcion;

    do {
        cout << "\n1. Agregar\n2. Listar\n3. Salir\nOpcion: ";
        cin >> opcion;

        if (opcion == 1) {
            Producto p;
            cout << "Codigo: "; cin >> p.codigo;
            cout << "Nombre: "; cin >> p.nombre;
            cout << "Cantidad: "; cin >> p.cantidad;
            inventario.push_back(p);
        } else if (opcion == 2) {
            for (int i = 0; i < inventario.size(); i++) {
                cout << inventario[i].nombre << " - " << inventario[i].cantidad << endl;
            }
        }
    } while (opcion != 3);
    return 0;
}
