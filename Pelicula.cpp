#include "Pelicula.h"
#include <iostream>
#include <iomanip>

using namespace std;

Pelicula::Pelicula(string t, float c, int d, string g, string dir, int a, string img) 
    : ContenidoMultimedia(t, c, d, g, img), director(dir), año(a) {
    // Agregar videos de muestra
    videos.push_back("Trailer Oficial - " + titulo);
    videos.push_back("Making Of - " + titulo);
    videos.push_back("Escenas Eliminadas - " + titulo);
}

void Pelicula::mostrarInfo() {
    cout << "\n======== PELICULA ========\n";
    cout << "Titulo: " << titulo << "\n";
    cout << "Calificación: " << fixed << setprecision(1) << calificacion << "/10\n";
    cout << "Duración: " << duracion << " minutos\n";
    cout << "Genero: " << genero << "\n";
    cout << "Director: " << director << "\n";
    cout << "Año: " << año << "\n";
    cout << "=========================\n";
}

void Pelicula::mostrarVideos() {
    cout << "\n--- VIDEOS DISPONIBLES ---\n";
    for(size_t i = 0; i < videos.size(); i++) {
        cout << (i+1) << ". " << videos[i] << "\n";
    }
    cout << "-------------------------\n";
}

void Pelicula::mostrarImagen() {
    cout << "\n--- IMAGEN/POSTER ---\n";
    cout << "imagen " << imagen << "\n";
    cout << "--------------------\n";
}