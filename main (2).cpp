#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Producto {
    string codigo;
    string nombre;
    int cantidad;
};

// Función específica para mostrar menú
void mostrarMenu() {
    cout << "\n1. Agregar Producto\n2. Listar Todo\n3. Salir\nSeleccione: ";
}

// Función específica para agregar
void agregarProducto(vector<Producto>& inventario) {
    Producto p;
    cout << "Codigo: "; cin >> p.codigo;
    cout << "Nombre: "; cin >> p.nombre;
    cout << "Cantidad: "; cin >> p.cantidad;
    inventario.push_back(p);
}

// Función específica para listar
void listarProductos(const vector<Producto>& inventario) {
    for (const auto& p : inventario) {
        cout << "Cod: " << p.codigo << " | " << p.nombre << " | Cant: " << p.cantidad << endl;
    }
}

int main() {
    vector<Producto> inventario;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        switch(opcion) {
            case 1: agregarProducto(inventario); break;
            case 2: listarProductos(inventario); break;
        }
    } while (opcion != 3);
    return 0;
}
