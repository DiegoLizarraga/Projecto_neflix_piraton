#ifndef SERIE_H
#define SERIE_H

#include "ContenidoMultimedia.h"

// Clase Serie
class Serie : public ContenidoMultimedia {
private:
    int temporadas;
    int episodios;
    string creador;

public:
    Serie(string t, float c, int d, string g, int temp, int ep, string cr, string img);
    
    void mostrarInfo() override;
    void mostrarVideos() override;
    void mostrarImagen() override;
};

#endif