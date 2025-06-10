#ifndef PELICULA_H
#define PELICULA_H

#include "ContenidoMultimedia.h"

// Clase Película
class Pelicula : public ContenidoMultimedia {
private:
    string director;
    int año;

public:
    Pelicula(string t, float c, int d, string g, string dir, int a, string img);
    
    void mostrarInfo() override;
    void mostrarVideos() override;
    void mostrarImagen() override;
};

#endif