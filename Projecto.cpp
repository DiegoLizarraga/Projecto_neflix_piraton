#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

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
    ContenidoMultimedia(string t, float c, int d, string g, string img) 
        : titulo(t), calificacion(c), duracion(d), genero(g), imagen(img) {}
    
    virtual void mostrarInfo() = 0;
    virtual void mostrarVideos() = 0;
    virtual void mostrarImagen() = 0;
    
    string getTitulo() { return titulo; }
    float getCalificacion() { return calificacion; }
    int getDuracion() { return duracion; }
    string getGenero() { return genero; }
};

// Clase Película
class Pelicula : public ContenidoMultimedia {
private:
    string director;
    int año;

public:
    Pelicula(string t, float c, int d, string g, string dir, int a, string img) 
        : ContenidoMultimedia(t, c, d, g, img), director(dir), año(a) {
        // Agregar videos de muestra
        videos.push_back("Trailer Oficial - " + titulo);
        videos.push_back("Making Of - " + titulo);
        videos.push_back("Escenas Eliminadas - " + titulo);
    }
    
    void mostrarInfo() override {
        cout << "\n======== PELICULA ========\n";
        cout << "Titulo: " << titulo << "\n";
        cout << "Calificación: " << fixed << setprecision(1) << calificacion << "/10\n";
        cout << "Duración: " << duracion << " minutos\n";
        cout << "Genero: " << genero << "\n";
        cout << "Director: " << director << "\n";
        cout << "Año: " << año << "\n";
        cout << "=========================\n";
    }
    
    void mostrarVideos() override {
        cout << "\n--- VIDEOS DISPONIBLES ---\n";
        for(int i = 0; i < videos.size(); i++) {
            cout << (i+1) << ". " << videos[i] << "\n";
        }
        cout << "-------------------------\n";
    }
    
    void mostrarImagen() override {
        cout << "\n--- IMAGEN/POSTER ---\n";
        cout << "imagen " << imagen << "\n";
        cout << "--------------------\n";
    }
};

// Clase Serie
class Serie : public ContenidoMultimedia {
private:
    int temporadas;
    int episodios;
    string creador;

public:
    Serie(string t, float c, int d, string g, int temp, int ep, string cr, string img) 
        : ContenidoMultimedia(t, c, d, g, img), temporadas(temp), episodios(ep), creador(cr) {
        // Agregar videos de muestra
        videos.push_back("Trailer Temporada 1 - " + titulo);
        videos.push_back("Trailer Temporada " + to_string(temporadas) + " - " + titulo);
        videos.push_back("Bloopers - " + titulo);
        videos.push_back("Entrevista con el reparto - " + titulo);
    }
    
    void mostrarInfo() override {
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
    
    void mostrarVideos() override {
        cout << "\n--- VIDEOS DISPONIBLES ---\n";
        for(int i = 0; i < videos.size(); i++) {
            cout << (i+1) << ". " << videos[i] << "\n";
        }
        cout << "-------------------------\n";
    }
    
    void mostrarImagen() override {
        cout << "\n--- IMAGEN/POSTER ---\n";
        cout << "imagen " << imagen << "\n";
        cout << "--------------------\n";
    }
};

// Clase Catálogo
class Catalogo {
private:
    vector<ContenidoMultimedia*> contenido;

public:
    Catalogo() {
        // Inicializar con 20 elementos (10 películas y 10 series)
        
        // PELÍCULAS
        contenido.push_back(new Pelicula("La princesa Mononoke", 8.4, 134, "Fantasía/Aventura", "Hayao Miyazaki", 1997, "Poster con San y los espíritus del bosque"));
        contenido.push_back(new Pelicula("El viaje de Chihiro", 8.6, 125, "Fantasía/Aventura", "Hayao Miyazaki", 2001, "Poster de Chihiro en el mundo de los espíritus"));
        contenido.push_back(new Pelicula("Look Back", 8.1, 90, "Drama/Slice of Life", "Kiyotaka Oshiyama", 2021, "Poster de dos lesbianas"));
        contenido.push_back(new Pelicula("Star Wars: Episodio I - La amenaza fantasma", 6.5, 136, "Ciencia ficción", "George Lucas", 1999, "Poster con Darth Maul y Anakin"));
        contenido.push_back(new Pelicula("Star Wars: Episodio II - El ataque de los clones", 6.5, 142, "Ciencia ficción", "George Lucas", 2002, "Poster con Anakin y Padmé"));
        contenido.push_back(new Pelicula("Star Wars: Episodio III - La venganza de los Sith", 7.5, 140, "Ciencia ficción", "George Lucas", 2005, "Poster con Anakin y Obi-Wan luchando"));
        contenido.push_back(new Pelicula("Star Wars: Episodio IV - Una nueva esperanza", 8.6, 121, "Ciencia ficción", "George Lucas", 1977, "Poster clásico de Star Wars"));
        contenido.push_back(new Pelicula("Star Wars: Episodio V - El imperio contraataca", 8.7, 124, "Ciencia ficción", "Irvin Kershner", 1980, "Poster con Han Solo y Leia"));
        contenido.push_back(new Pelicula("Star Wars: Episodio VI - El retorno del Jedi", 8.3, 131, "Ciencia ficción", "Richard Marquand", 1983, "Poster con Luke y Darth Vader"));
                
        // SERIES
        contenido.push_back(new Serie("Jujutsu Kaisen", 8.7, 24, "Acción/Fantasía oscura", 2, 47, "Sunghoo Park", "Poster con Yuji Itadori y Sukuna"));
        contenido.push_back(new Serie("Pokémon", 7.5, 22, "Aventura/Fantasía", 25, 1200, "Kunihiko Yuyama", "Poster con Pikachu y Ash"));
        contenido.push_back(new Serie("Violet Evergarden", 8.8, 24, "Drama/Fantasía", 1, 13, "Taichi Ishidate", "Poster con violet"));
        contenido.push_back(new Serie("Kimetsu no Yaiba", 8.7, 24, "Acción/Fantasía oscura", 3, 55, "Haruo Sotozaki", "Poster con Tanjiro y Nezuko"));
        contenido.push_back(new Serie("Attack on Titan", 9.0, 24, "Acción/Fantasía oscura", 4, 87, "Tetsurō Araki", "Poster con Eren y los titanes"));
        contenido.push_back(new Serie("Blue Lock", 8.3, 24, "Deporte/Drama", 1, 24, "Tetsuaki Watanabe", "Poster con los jugadores de fútbol"));
        contenido.push_back(new Serie("Star Wars: The Clone Wars", 8.4, 22, "Ciencia ficción", 7, 133, "Dave Filoni", "Poster con Anakin y Ahsoka"));
        contenido.push_back(new Serie("Ann", 7.9, 45, "Drama/Thriller", 1, 10, "Unknown", "Poster de la niña pelirroja"));
        contenido.push_back(new Serie("Nadie nos va a extrañar", 8.1, 45, "Drama/Crimen", 1, 10, "Unknown", "Niños de mexico noventeros"));
        contenido.push_back(new Serie("Si la vida te da mandarinas", 7.8, 45, "Drama/Comedia", 1, 10, "Unknown", "un dulce k-drama"));
        contenido.push_back(new Serie("Goblin", 8.9, 70, "Fantasía/Romance", 1, 16, "Lee Eung-bok", "Poster del mejor k.drama de la historia"));
        contenido.push_back(new Serie("Alien Stage", 8.5, 15, "Ciencia ficción/Musical", 1, 6, "Unknown", "nose la sofi jsjsjs"));
    }
    
    ~Catalogo() {
        for(auto* item : contenido) {
            delete item;
        }
    }
    
    void mostrarCatalogo() {
        cout << "\n ===== CATALOGO NETFLIX PIRATON ===== \n\n";
        for(int i = 0; i < contenido.size(); i++) {
            cout << (i+1) << ". " << contenido[i]->getTitulo() 
                 << " ⭐ " << fixed << setprecision(1) << contenido[i]->getCalificacion() 
                 << " | " << contenido[i]->getDuracion() << " min"
                 << " | " << contenido[i]->getGenero() << "\n";
        }
        cout << "\n================================\n";
    }
    
    void seleccionarContenido(int opcion) {
        if(opcion < 1 || opcion > contenido.size()) {
            cout << " Opcion invalida. Por favor selecciona un número del 1 al " << contenido.size() << "\n";
            return;
        }
        
        ContenidoMultimedia* seleccionado = contenido[opcion-1];
        
        // Mostrar información básica
        seleccionado->mostrarInfo();
        
        // Mostrar imagen/poster
        seleccionado->mostrarImagen();
        
        // Mostrar videos disponibles
        seleccionado->mostrarVideos();
        
        // Menú de opciones adicionales
        cout << "\n¿Que te gustaria hacer?\n";
        cout << "1.  Reproducir contenido\n";
        cout << "2.  Ver videos relacionados\n";
        cout << "3.  Volver al catalogo\n";
        cout << "Opcion: ";
        
        int subOpcion;
        cin >> subOpcion;
        
        switch(subOpcion) {
            case 1:
                cout << "\nReproduciendo: " << seleccionado->getTitulo() << "...\n";
                cout << "¡Disfruta tu contenido! \n";
                break;
            case 2:
                cout << "\n Mostrando videos relacionados:\n";
                seleccionado->mostrarVideos();
                break;
            case 3:
                cout << "\n Regresando al catalogo...\n";
                break;
            default:
                cout << " No se puede\n";
        }
    }
    
    void buscarPorGenero() {
        cout << "\n Generos disponibles:\n";
        cout << "1. Accion\n2. Drama\n3. Comedia\n4. Sci-Fi\n5. Fantasia\n";
        cout << "6. Crimen\n7. Romance\n8. Horror\n9. Thriller\n";
        cout << "\nIngresa parte del género a buscar: ";
        
        string genero;
        cin.ignore();
        getline(cin, genero);
        
        cout << "\n🔍 Resultados para '" << genero << "':\n";
        bool encontrado = false;
        
        for(int i = 0; i < contenido.size(); i++) {
            if(contenido[i]->getGenero().find(genero) != string::npos ||
               contenido[i]->getGenero().find(genero) != string::npos) {
                cout << (i+1) << ". " << contenido[i]->getTitulo() 
                     << " ⭐ " << contenido[i]->getCalificacion() << "\n";
                encontrado = true;
            }
        }
        
        if(!encontrado) {
            cout << " No se encontraron resultados para ese genero.\n";
        }
    }
    
    void mostrarEstadisticas() {
        cout << "\n ESTADISTICAS DEL CATALOGO:\n";
        cout << "===============================\n";
        
        int peliculas = 0, series = 0;
        float promedioCalif = 0;
        int duracionTotal = 0;
        
        for(auto* item : contenido) {
            // Verificar si es película o serie (simplificado)
            if(typeid(*item) == typeid(Pelicula)) {
                peliculas++;
            } else {
                series++;
            }
            promedioCalif += item->getCalificacion();
            duracionTotal += item->getDuracion();
        }
        
        promedioCalif /= contenido.size();
        
        cout << " Peliculas: " << peliculas << "\n";
        cout << " Series: " << series << "\n";
        cout << " Calificación promedio: " << fixed << setprecision(1) << promedioCalif << "/10\n";
        cout << " Duracion promedio: " << (duracionTotal/contenido.size()) << " minutos\n";
        cout << " Total de contenido: " << contenido.size() << " títulos\n";
        cout << "===============================\n";
    }
};

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
                cout << "\ Ingresa el número del contenido que deseas ver: ";
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