#include <Enemigos.h>
using namespace std;

//constructor
Enemigo()
{};

Enemigo(string nombre, string descripcion, int vida, int energia, int da�o)
{

	Nombre = nombre;
	Descripcion = descripcion;
	Vida = vida;
	Energia = energia;
	Da�o = da�o;
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

void set_Da�o(int da�o)
{
	Da�o = da�o;
};
int get_Da�o() const
{
	return Da�o;
};

void set_Movimientos(const vector <string&> movimientos)
{
	vector <string&> Movimientos = vector <string&> movimientos;
};
vector <string> get_Movimientos() const
{
	return vector <string&> movimientos;
};