#ifndef CATALOGO_H
#define CATALOGO_H

#include "ContenidoMultimedia.h"
#include <vector>

using namespace std;

// Clase Catálogo
class Catalogo {
private:
    vector<ContenidoMultimedia*> contenido;

public:
    Catalogo();
    ~Catalogo();
    
    void mostrarCatalogo();
    void seleccionarContenido(int opcion);
    void buscarPorGenero();
    void mostrarEstadisticas();
};

#endif