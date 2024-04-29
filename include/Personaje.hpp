#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Personaje
{
private:
    string Nombre;
    int Vida;
    int Energia;
    stack<string> Ataques;
public:
    // Constructor por defecto
    Personaje();

    // Constructor con parámetros
    Personaje(const string& nombre, int vida, int energia, const stack<string>& ataques);

    // Funciones de modificación y acceso
    void set_Nombre(const string& nombre);
    string get_Nombre() const;

    void set_Vida(int vida);
    int get_Vida() const;

    void set_Energia(int energia);
    int get_Energia() const;

    void set_Ataques(const stack<string>& ataques);
    stack<string> get_Ataques() const;
};
