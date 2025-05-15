#include <iostream>
#include <string>
using namespace std;
class Nodo {
public:
    int codigo;
    string nombre;
    int cantidad;
    float precio;
    Nodo* siguiente;
    Nodo(int cod, string nom, int cant, float prec) {
        codigo = cod;
        nombre = nom;
        cantidad = cant;
        precio = prec;
        siguiente = nullptr;
    }
};

 
void insertarAlInicio(Nodo*& cabeza, int codigo, string nombre, int cantidad, float precio) {
    Nodo* nuevo = new Nodo(codigo, nombre, cantidad, precio);
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

 
void mostrarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << "Codigo: " << actual->codigo
<< ", Nombre: " << actual->nombre
<< ", Cantidad: " << actual->cantidad
<< ", Precio: $" << actual->precio << endl;
        actual = actual->siguiente;
    }
    cout << "------------------\n";
}
void buscarProducto(Nodo* cabeza, int codigo) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->codigo == codigo) {
            cout << "Producto encontrado: " << actual->nombre << ", Cantidad: " << actual->cantidad << ", Precio: $" << actual->precio << endl;
            return;
        }
        actual = actual->siguiente;
    }
    cout << "Producto con código " << codigo << " no encontrado.\n";
}

 
void modificarProducto(Nodo* cabeza, int codigo) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        if (actual->codigo == codigo) {
            cout << "Producto encontrado: " << actual->nombre << endl;
            cout << "Ingrese nueva cantidad: ";
            cin >> actual->cantidad;
            cout << "Ingrese nuevo precio: ";
            cin >> actual->precio;
            cout << "Producto modificado exitosamente.\n";
            return;
        }
        actual = actual->siguiente;
    }
    cout << "Producto no encontrado.\n";
}
void eliminarProducto(Nodo*& cabeza, int codigo) {
    Nodo* temp = cabeza;
    Nodo* anterior = nullptr;
    if (temp != nullptr && temp->codigo == codigo) {
        cabeza = temp->siguiente;
        delete temp;
        cout << "Producto eliminado.\n";
        return;
    }
    while (temp != nullptr && temp->codigo != codigo) {
        anterior = temp;
        temp = temp->siguiente;
    }
    if (temp == nullptr) {
        cout << "Producto no encontrado.\n";
        return;
    }
    anterior->siguiente = temp->siguiente;
    delete temp;
    cout << "Producto eliminado.\n";
}
int main() {
    Nodo* cabeza = nullptr;
    insertarAlInicio(cabeza, 103, "Mouse", 20, 19.99);
    insertarAlInicio(cabeza, 102, "Teclado", 10, 49.99);
    insertarAlInicio(cabeza, 101, "Laptop", 5, 999.99);
    cout << "Inventario actual:\n";
    mostrarLista(cabeza);
    cout << "\nBuscar producto:\n";
    buscarProducto(cabeza, 102);
    cout << "\nModificar producto:\n";
    modificarProducto(cabeza, 103);
    cout << "\nInventario actualizado:\n";
    mostrarLista(cabeza);
    cout << "\nVender producto:\n";
    cout << "\nInventario actualizado:\n";
    mostrarLista(cabeza);
    cout << "\nEliminar producto:\n";
    eliminarProducto(cabeza, 102);
    cout << "\nInventario final:\n";
    mostrarLista(cabeza);
    // Liberar memoria
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
    return 0;
}
