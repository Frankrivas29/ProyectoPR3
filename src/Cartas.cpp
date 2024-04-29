#include "cartas.hpp"
using namespace std;

// Constructor
Carta::Carta() {}

Carta::Carta(string nombre, string descripcion, int dano, int coste, bool usada)
{
    Nombre = nombre;
    Descripcion = descripcion;
    Dano = dano;
    Coste = coste;
    Usada = usada;
}

// Métodos para establecer y obtener los valores de los atributos
void Carta::set_Nombre(const string& nombre)
{
    Nombre = nombre;
}

string Carta::get_Nombre() const
{
    return Nombre;
}

void Carta::set_Descripcion(const string& descripcion)
{
    Descripcion = descripcion;
}

string Carta::get_Descripcion() const
{
    return Descripcion;
}

void Carta::set_Dano(int dano)
{
    Dano = dano;
}

int Carta::get_Dano() const
{
    return Dano;
}

void Carta::set_Coste(int coste)
{
    Coste = coste;
}

int Carta::get_Coste() const
{
    return Coste;
}

void Carta::set_Usada(bool usada)
{
    Usada = usada;
}

bool Carta::get_Usada() const
{
    return Usada;
}
