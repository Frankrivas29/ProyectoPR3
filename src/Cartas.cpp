#include <cartas.h>
using namespace std;
// Constructor
Carta()
{};

Carta(string nombre, string descripcion, int da�o, int coste, bool usada)
{

	Nombre = nombre;
	Descripcion = descripcion;
	Da�o = da�o;
	Coste = coste;
	Usada = usada;

};

// M�todos para establecer y obtener los valores de los atributos
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

};

string get_Descripcion() const
{

	return Descripcion;

};

void set_Da�o(int da�o)

{
	Da�o = da�o;
};

int get_Da�o() const
{

	return Da�o;

};

void set_Coste(int coste)
{
	Coste = coste;

};

int get_Coste() const
{
	return Coste;

};

void set_Usada(bool usada)
{

	Usada = usada;

}

bool get_Usada() const
{
	return Usada;
}


