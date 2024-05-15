#pragma once

#include <string>
using namespace std;

class Carta
{
private:
	string Nombre;
	string Descripcion;
	string Tipo;
	int ID;
	int Dano;
	int Coste;
	bool Usada;
	int ID_original;

public:

	Carta();


	Carta(string nombre, string descripcion, string tipo, int Id, int dano, int coste, bool usada);

	void set_Nombre(const string& nombre);
	string get_Nombre() const;

	void set_Descripcion(const string& descripcion);
	string get_Descripcion() const;

	void set_Tipo(const string& tipo);
	string get_Tipo() const;

	void set_ID(int Id);
	int get_ID() const;

	void set_Dano(int dano);
	int get_Dano() const;

	void set_Coste(int coste);
	int get_Coste() const;

	void set_Usada(bool usada);
	bool get_Usada() const;

	void set_ID_original(int Id_original);
	int get_ID_original() const;
};
