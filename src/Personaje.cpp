#include <Personaje.h>
using namespace std;

Personaje()
{};

Personaje(const string nombre, int vida, int energia, const stack <string&> ataques)
{
	Nombre = nombre;
	Vida = vida;
	Energia = energia;
	stack <string&> Ataques = stack <string&> ataques;
};

void set_Nombre(const string& nombre)
{
	Nombre = nombre;
};
string get_Nombre() const
{
	return Nombre;
};

int set_Vida(int vida)
{
	Vida = vida;
};
int get_Vida()
{
	return Vida;
};

int set_Energia(int energia)
{
	Energia = energia;
};
int get_Energia()
{
	return Energia;
};

void set_Ataques(const stack <string&> ataques)
{
	stack <string&> Ataques = stack <string&> ataques;
};
stack <string> get_Ataques() const
{
	return stack <string&> Ataques;
};