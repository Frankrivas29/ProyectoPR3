#pragma once

#include <string>
using namespace std;

class Carta
{
private:
    string Nombre;       // Nombre de la carta
    string Descripcion;  // Descripción de la carta
    string Tipo;
    int ID;
    int Dano;            // Valor de daño de la carta
    int Coste;           // Costo de la carta
    bool Usada;          // Indica si la carta ha sido usada

public:
    // Constructor sin parámetros
    Carta();

    // Constructor con parámetros
    Carta(string nombre, string descripcion, string tipo,int Id, int dano, int coste, bool usada);

    // Métodos para establecer y obtener los valores de los atributos
    void set_Nombre(const string& nombre);
    string get_Nombre() const;

    void set_Descripcion(const string& descripcion);
    string get_Descripcion() const;

    void set_Tipo(const string& tipo);
    string get_Tipo() const;

    void set_ID(int Id);
    int get_ID() const;

    void set_Dano(int dano);
    int get_Dano() const;

    void set_Coste(int coste);
    int get_Coste() const;

    void set_Usada(bool usada);
    bool get_Usada() const;
};
