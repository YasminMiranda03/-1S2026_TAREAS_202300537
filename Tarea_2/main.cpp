#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

void leerArchivo() {
    try {
        ifstream archivo("inventario.inv");

        if (!archivo) {
            throw runtime_error("Error: No se pudo abrir el archivo inventario.inv");
        }

        string nombre, ubicacion;
        int cantidad;
        double precio;

        cout << "\n===== CONTENIDO DEL INVENTARIO =====\n";

        while (archivo >> nombre >> cantidad >> precio >> ubicacion) {
            cout << "Producto: " << nombre
                 << " | Cantidad: " << cantidad
                 << " | Precio: Q" << precio
                 << " | Ubicacion: " << ubicacion << endl;
        }

        archivo.close();
        cout << "====================================\n\n";

    } catch (exception &e) {
        cout << e.what() << endl;
    }
}

int main() {
    int opcion;

    do {
        cout << "Menu\n";
        cout << "1. Leer archivo .inv e imprimir contenido\n";
        cout << "2. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                leerArchivo();
                break;
            case 2:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }

    } while (opcion != 2);

    return 0;
}