#ifndef CONTENIDO_MULTIMEDIA_H
#define CONTENIDO_MULTIMEDIA_H

#include <string>
#include <vector>

using namespace std;

// Clase base para contenido multimedia
class ContenidoMultimedia {
protected:
    string titulo;
    float calificacion;
    int duracion; // en minutos
    string genero;
    string imagen;
    vector<string> videos;

public:
    ContenidoMultimedia(string t, float c, int d, string g, string img);
    
    virtual void mostrarInfo() = 0;
    virtual void mostrarVideos() = 0;
    virtual void mostrarImagen() = 0;
    virtual ~ContenidoMultimedia() = default;
    
    string getTitulo() { return titulo; }
    float getCalificacion() { return calificacion; }
    int getDuracion() { return duracion; }
    string getGenero() { return genero; }
};

#endif