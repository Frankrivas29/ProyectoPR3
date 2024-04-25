#include <Enemigos.h>
using namespace std;

//constructor
Enemigo()
{};

Enemigo(string nombre, string descripcion, int vida, int energia, int daño)
{

	Nombre = nombre;
	Descripcion = descripcion;
	Vida = vida;
	Energia = energia;
	Daño = daño;
	vector <string&> Movimientos = vector <string&> movimientos;
};

void set_Nombre(const string& nombre)
{
	Nombre = nombre;

};
string get_Nombre() const

{
	return Nombre;
};

void set_Descripcion(const string& descripcion)
{

	Descripcion = descripcion;

}
;
string get_Descripcion() const
{
	return Descripcion;
};

void set_Vida(int vida)
{
	Vida = vida;
};
int get_Vida() const
{
	return Vida;
};

void set_Energia(int energia) 
{
	Energia = energia;

};
int get_Energia() const
{
	return Energia;
};

void set_Daño(int daño)
{
	Daño = daño;
};
int get_Daño() const
{
	return Daño;
};

void set_Movimientos(const vector <string&> movimientos)
{
	vector <string&> Movimientos = vector <string&> movimientos;
};
vector <string> get_Movimientos() const
{
	return vector <string&> movimientos;
};