#pragma once

#include <string> // Incluir la librer�a string si est�s utilizando la clase string
using namespace std;

class Carta
{
private:
    string Nombre;       // Nombre de la carta
    string Descripcion;  // Descripci�n de la carta
    int Da�o;                 // Valor de da�o de la carta
    int Coste;                // Costo de la carta
    bool Usada;               // Indica si la carta ha sido usada

public:
    // Constructor
    Carta();

    // M�todos para establecer y obtener los valores de los atributos
    void set_Nombre(const string& nombre);
    string get_Nombre() const;

    void set_Descripcion(const string& descripcion);
    string get_Descripcion() const;

    void set_Da�o(int da�o);
    int get_Da�o() const;

    void set_Coste(int coste);
    int get_Coste() const;

    void set_Usada(bool usada);
    bool get_Usada() const;
}