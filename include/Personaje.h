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
stack <string> Ataques;
public:
	   //constructor
	   Personaje();

	   void set_Nombre(const string& nombre);
	   string get_Nombre() const;

	   int set_Vida(int vida);
	   int get_Vida();

	   int set_Energia(int energia);
	   int get_Energia();

	   void set_Ataques(const stack <string&> ataques);
	   stack <string> get_Ataques() const;
}