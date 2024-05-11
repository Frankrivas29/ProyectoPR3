#include "Personaje.hpp" // Incluir el archivo de encabezado correspondiente

// Constructor por defecto
Personaje::Personaje() {}

// Constructor con parámetros
Personaje::Personaje(const string& nombre, int vida, int energia)
    : Nombre(nombre), Vida(vida), Energia(energia) {}

// Funciones de modificación y acceso
void Personaje::set_Nombre(const string& nombre) {
    Nombre = nombre;
}

string Personaje::get_Nombre() const {
    return Nombre;
}

void Personaje::set_Vida(int vida) {
    Vida = vida;
}

int Personaje::get_Vida() const {
    return Vida;
}

void Personaje::set_Energia(int energia) {
    Energia = energia;
}

int Personaje::get_Energia() const {
    return Energia;
}
