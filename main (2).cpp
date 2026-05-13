#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Producto {
    string codigo;
    string nombre;
    int cantidad;
};

// PASO 2: FUNCION DE AYUDA (Reutilizable para evitar duplicados y para actualizar)
int buscarProducto(const vector<Producto>& inventario, string codigo) {
    for (int i = 0; i < inventario.size(); i++) {
        if (inventario[i].codigo == codigo) return i;
    }
    return -1;
}

void mostrarMenu() {
    cout << "\n--- GADGETXPRESS SISTEMA ---" << endl;
    cout << "1. Agregar\n2. Listar\n3. Actualizar Cantidad\n4. Bajo Stock\n5. Salir\nOpcion: ";
}

void agregarProducto(vector<Producto>& inventario) {
    string cod;
    cout << "Codigo: "; cin >> cod;
    if (buscarProducto(inventario, cod) != -1) {
        cout << "Error: El producto ya existe." << endl;
    } else {
        Producto p; p.codigo = cod;
        cout << "Nombre: "; cin.ignore(); getline(cin, p.nombre);
        cout << "Cantidad: "; cin >> p.cantidad;
        inventario.push_back(p);
    }
}

void actualizarCantidad(vector<Producto>& inventario) {
    string cod;
    cout << "Codigo a buscar: "; cin >> cod;
    int pos = buscarProducto(inventario, cod);
    if (pos != -1) {
        cout << "Nueva cantidad: "; cin >> inventario[pos].cantidad;
    } else {
        cout << "No encontrado." << endl;
    }
}

void reporteBajoStock(const vector<Producto>& inventario) {
    cout << "\n--- BAJO STOCK (< 5 unidades) ---" << endl;
    for (const auto& p : inventario) {
        if (p.cantidad < 5) cout << p.nombre << " | Stock: " << p.cantidad << endl;
    }
}

int main() {
    vector<Producto> inventario;
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        switch (opcion) {
            case 1: agregarProducto(inventario); break;
            case 2: // Listar (puedes llamar a una función simple aquí)
                for(const auto& p : inventario) cout << p.nombre << " [" << p.codigo << "]" << endl;
                break;
            case 3: actualizarCantidad(inventario); break;
            case 4: reporteBajoStock(inventario); break;
        }
    } while (opcion != 5);
    return 0;
}
