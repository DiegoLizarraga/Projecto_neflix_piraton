# Makefile para el proyecto Sistema de Streaming

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Archivos fuente
SOURCES = main.cpp ContenidoMultimedia.cpp Pelicula.cpp Serie.cpp Catalogo.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = streaming

# Regla principal
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Reglas para crear archivos objeto
main.o: main.cpp Catalogo.h
	$(CXX) $(CXXFLAGS) -c main.cpp

ContenidoMultimedia.o: ContenidoMultimedia.cpp ContenidoMultimedia.h
	$(CXX) $(CXXFLAGS) -c ContenidoMultimedia.cpp

Pelicula.o: Pelicula.cpp Pelicula.h ContenidoMultimedia.h
	$(CXX) $(CXXFLAGS) -c Pelicula.cpp

Serie.o: Serie.cpp Serie.h ContenidoMultimedia.h
	$(CXX) $(CXXFLAGS) -c Serie.cpp

Catalogo.o: Catalogo.cpp Catalogo.h ContenidoMultimedia.h Pelicula.h Serie.h
	$(CXX) $(CXXFLAGS) -c Catalogo.cpp

# Limpiar archivos compilados
clean:
	rm -f $(OBJECTS) $(TARGET)

# Compilar y ejecutar
run: $(TARGET)
	./$(TARGET)

.PHONY: clean run