#include <cartas.h>
using namespace std;
// Constructor
Cartas()
{};

Cartas(string nombre, string descripcion, int daño, int coste, bool usada)
{

};

// Métodos para establecer y obtener los valores de los atributos
void set_Nombre(const string& nombre);

string get_Nombre() const;

void set_Descripcion(const string& descripcion);

string get_Descripcion() const;

void set_Daño(int daño);

int get_Daño() const;

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


