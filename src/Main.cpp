/*Lista de cosas que tengo que tener hechas pronto:
* -declarar las clases
* -crear la informacion de las cartas
* -crear a los enemigos
*
* -objetivo, antes del proximo fin de semana.



*/
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <Enemigos.hpp>
#include <Cartas.hpp>
#include <Personaje.hpp>
using namespace std;

void tutorial();
void Menu();
void pausa();
void limpiarPantalla();

void pausa() {
	cout << "Presione enter para continuar";
	cin.ignore(); // Ignora la entrada anterior (el Enter)
	cin.get();    // Espera a que se presione Enter nuevamente
}

void limpiarPantalla() {
	system("clear"); // Limpia la pantalla en sistemas Unix/Linux
}

void tutorial()
{
	//Inicio de la aventura
	cout << "|Dungeons and Cards (creado por Nantendo)|" << endl << "Bienvenido Caballero, ante ti se encuentra una gran mazmorra" << endl << "Dentro toda clase de peligros te esperan, junto a grandes tesoros" << endl << "Para salir vivo de tu mision, deberas usar una serie de cartas magicas" << endl << "Necesitas de mi guia, o te aventuraras solo por tu cuenta?" << endl;	
	int opcion = 0;
	bool terminar = false;
	do
	{
		
		cout << "Ingrese 1 para escuchar la explicacion, ingrese 2 para continuar solo" << endl;
		cin >> opcion;
		limpiarPantalla();
		if (opcion == 1)
		{
			
			cout << "Entendido, empezemos la explicacion" << endl << "Para empezar, tendras un mazo de cartas con todas tus opciones, este mazo se te repartira de forma aleatoria, en grupo de 4" << endl << "Cada Carta tendra un dano, y un coste" << endl << "Seras capaz de escoger un maximo de 4 cartas por turno" << endl << "Tu objetivo sera lograr un mayor puntaje de da�o que tu oponente" << endl << "el usuario que saque un mayor puntaje, sera el que realizara el ataque" << endl << "Dicho puntaje se vera alterado por diversas condiciones, si tu ataque coincide con el tipo de ataque del oponente, los danos se cancelan" << endl << "Si dos cartas del mismo tipo estan juntas en tu stack, su  da�o se duplicara" << endl << "Y si tu coste de energia es superior a la energia actual, no podras atacar" << endl << "Deberas anticiparte a tu rival, aprender sus movimientos, y lograr usar un combo que sea efectivo" << endl << "El primero en quedarse sin vida, sera derrotado" << endl << "tendras una barra de vida y energia, si no tienes energia suficiente, ciertas cartas no podran ser usadas" << endl << "Y si te quedas sin vida, seras echado de la mazmorra y tendras que volver a empezar" << endl << "Ahora que ya sabes lo basico, adentrate en la mazmorra..." << endl;
			pausa();
			limpiarPantalla();
			terminar = true;
		}

		else if (opcion == 2)
		{
		
			cout << "Bien, si no necesitas mi ayuda, adentrate en la mazmorra..." << endl;
			pausa();
			limpiarPantalla();
			terminar = true;
		}

		else

		{

			cout << "Opcion Incorrecta" << endl;
			terminar = false;

		}
	} 
	while (terminar == false);
	Menu();
}

void Menu()
{	
	
	int opcion = 0;
	do
	{
	cout << "|Menu|" << endl << "|1| Entrar a la mazmorra" << endl << "|2| Creacion del mazo" << endl << "|3| Salir" << endl;
	cout << "Ingrese una opcion" << endl;
	cin >> opcion;

	if (opcion == 1)
	{
		cout << "Aqui empezaran los combates, no esta terminado" << endl;
	}

	else if (opcion == 2)
	{
		cout << "Aqui manejaras el mazo de cartas, no esta terminado" << endl;
	}

	else if (opcion == 3)
	{
		cout << "Esperamos que hayas disfrutado de tu aventura, adios..." << endl;
	}

	}

	while (opcion != 1 && opcion != 2 && opcion != 3);
}

int main()

{
	tutorial();
	Enemigo enemigo1("Muneco", "Objeto de entrenamiento", 10, 5, 3);

	

}