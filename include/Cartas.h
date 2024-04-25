#pragma once

#include <string> // Incluir la librería string si estás utilizando la clase string
using namespace std;

class Carta
{
private:
    string Nombre;       // Nombre de la carta
    string Descripcion;  // Descripción de la carta
    int Daño;                 // Valor de daño de la carta
    int Coste;                // Costo de la carta
    bool Usada;               // Indica si la carta ha sido usada

public:
    // Constructor
    Carta();

    // Métodos para establecer y obtener los valores de los atributos
    void set_Nombre(const string& nombre);
    string get_Nombre() const;

    void set_Descripcion(const string& descripcion);
    string get_Descripcion() const;

    void set_Daño(int daño);
    int get_Daño() const;

    void set_Coste(int coste);
    int get_Coste() const;

    void set_Usada(bool usada);
    bool get_Usada() const;
}