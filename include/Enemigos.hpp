#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Enemigo {
private:
    string Nombre;
    string Descripcion;
    int Vida;
    int Energia;
    int Dano;

public:
    // Constructor
    Enemigo(string nombre, string descripcion, int vida, int energia, int dano);

    // Funciones de acceso
    void set_Nombre(const string& nombre);
    string get_Nombre() const;

    void set_Descripcion(const string& descripcion);
    string get_Descripcion() const;

    void set_Vida(int vida);
    int get_Vida() const;

    void set_Energia(int energia);
    int get_Energia() const;

    void set_Dano(int dano);
    int get_Dano() const;

    // Declaración de la función Mostrar_Datos
    void Mostrar_Datos();
};
