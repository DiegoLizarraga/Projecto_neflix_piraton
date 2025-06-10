#include <iostream>
#include "Catalogo.h"

using namespace std;

int main() {
    cout << " ¡Bienvenido a tu Sistema de Streaming! \n";
    cout << "==========================================\n";
    
    Catalogo catalogo;
    int opcion;
    
    do {
        cout << "\n MENU PRINCIPAL:\n";
        cout << "==================\n";
        cout << "1.  Mostrar catalogo completo\n";
        cout << "2.  Seleccionar contenido\n";
        cout << "3.  Buscar por genero\n";
        cout << "4.  Ver estadisticas\n";
        cout << "5.  Salir\n";
        cout << "\nSelecciona una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                catalogo.mostrarCatalogo();
                break;
                
            case 2: {
                catalogo.mostrarCatalogo();
                cout << "Ingresa el número del contenido que deseas ver: ";
                int seleccion;
                cin >> seleccion;
                catalogo.seleccionarContenido(seleccion);
                break;
            }
            
            case 3:
                catalogo.buscarPorGenero();
                break;
                
            case 4:
                catalogo.mostrarEstadisticas();
                break;
                
            case 5:
                cout << "\n ¡Gracias por usar nuestro sistema de streaming!\n";
                cout << "¡Hasta la proxima! \n";
                break;
                
            default:
                cout << " Opcion no valida. Por favor intenta de nuevo.\n";
        }
        
    } while(opcion != 5);
    
    return 0;
}