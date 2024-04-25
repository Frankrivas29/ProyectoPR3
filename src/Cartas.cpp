#include <cartas.h>
using namespace std;
// Constructor
Carta()
{};

Carta(string nombre, string descripcion, int daño, int coste, bool usada)
{

	Nombre = nombre;
	Descripcion = descripcion;
	Daño = daño;
	Coste = coste;
	Usada = usada;

};

// Métodos para establecer y obtener los valores de los atributos
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

void set_Daño(int daño)

{
	Daño = daño;
};

int get_Daño() const
{

	return Daño;

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


