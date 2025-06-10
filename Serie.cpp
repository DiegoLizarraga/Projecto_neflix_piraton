#include "Serie.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Serie::Serie(string t, float c, int d, string g, int temp, int ep, string cr, string img) 
    : ContenidoMultimedia(t, c, d, g, img), temporadas(temp), episodios(ep), creador(cr) {
    // Agregar videos de muestra
    videos.push_back("Trailer Temporada 1 - " + titulo);
    videos.push_back("Trailer Temporada " + to_string(temporadas) + " - " + titulo);
    videos.push_back("Bloopers - " + titulo);
    videos.push_back("Entrevista con el reparto - " + titulo);
}

void Serie::mostrarInfo() {
    cout << "\n========= SERIE ==========\n";
    cout << "Título: " << titulo << "\n";
    cout << "Calificación: " << fixed << setprecision(1) << calificacion << "/10\n";
    cout << "Duración por episodio: " << duracion << " minutos\n";
    cout << "Género: " << genero << "\n";
    cout << "Temporadas: " << temporadas << "\n";
    cout << "Episodios totales: " << episodios << "\n";
    cout << "Creador: " << creador << "\n";
    cout << "=========================\n";
}

void Serie::mostrarVideos() {
    cout << "\n--- VIDEOS DISPONIBLES ---\n";
    for(size_t i = 0; i < videos.size(); i++) {
        cout << (i+1) << ". " << videos[i] << "\n";
    }
    cout << "-------------------------\n";
}

void Serie::mostrarImagen() {
    cout << "\n--- IMAGEN/POSTER ---\n";
    cout << "imagen " << imagen << "\n";
    cout << "--------------------\n";
}