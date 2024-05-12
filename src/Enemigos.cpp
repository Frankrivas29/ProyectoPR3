#include "Enemigos.hpp"

// Constructor
Enemigo::Enemigo(string nombre, string descripcion, int Id, int vida, int energia, int dano)
    : Nombre(nombre), Descripcion(descripcion), ID(Id), Vida(vida), Energia(energia), Dano(dano) {}

// Implementación de las funciones de acceso

void Enemigo::set_Nombre(const string& nombre) {
    Nombre = nombre;
}

string Enemigo::get_Nombre() const {
    return Nombre;
}

void Enemigo::set_Descripcion(const string& descripcion) {
    Descripcion = descripcion;
}

string Enemigo::get_Descripcion() const {
    return Descripcion;
}

void Enemigo::set_ID(int Id) {
    ID = Id;
}

int Enemigo::get_ID() const {
    return ID;
}

void Enemigo::set_Vida(int vida) {
    Vida = vida;
}

int Enemigo::get_Vida() const {
    return Vida;
}

void Enemigo::set_Energia(int energia) {
    Energia = energia;
}

int Enemigo::get_Energia() const {
    return Energia;
}

void Enemigo::set_Dano(int dano) {
    Dano = dano;
}

int Enemigo::get_Dano() const {
    return Dano;
}
