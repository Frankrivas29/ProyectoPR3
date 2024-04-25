#pragma once
#include <string>
#include <vector>// Incluir la librería string si estás utilizando la clase string
using namespace std;

class Enemigo 
{
private: string nombre;
string descripcion;
int vida;
int energia;
int daño;
vector <string> movimientos;

public: 
//constructor
Enemigo();

void set_Nombre(const string& nombre);
string get_Nombre() const;

void set_Descripcion(const string& descripcion);
string get_Descripcion() const;

void set_Vida(int vida);
int get_Vida() const;

void set_Energia(int energia);
int get_Energia() const;

void set_Daño(int daño);
int get_Daño() const;

void set_Movimientos(const vector <string&> movimientos);
vector <string> get_Movimientos() const;
}