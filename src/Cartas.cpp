#include <cartas.h>
using namespace std;
// Constructor
Cartas()
{};

Cartas(string nombre, string descripcion, int da�o, int coste, bool usada)
{

};

// M�todos para establecer y obtener los valores de los atributos
void set_Nombre(const string& nombre);

string get_Nombre() const;

void set_Descripcion(const string& descripcion);

string get_Descripcion() const;

void set_Da�o(int da�o);

int get_Da�o() const;

void set_Coste(int coste);

int get_Coste() const;

void set_Usada(bool usada)
{

	Usada = usada;

}

bool get_Usada() const
{
	return false;
}


