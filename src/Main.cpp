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

vector <Carta> mazo_total;
vector <Carta> mazo_actual;

void tutorial();
void Menu();
void pausa();
void limpiarPantalla();
void Cartas_mazo();

void pausa() {
	cout << "Presione enter para continuar";
	cin.ignore(); // Ignora la entrada anterior (el Enter)
	cin.get();    // Espera a que se presione Enter nuevamente
}

void limpiarPantalla() {
	system("clear"); // Limpia la pantalla en sistemas Unix/Linux
}



int opcion = 0;

void Menu()
{	
	
	
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
		Cartas_mazo();
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
	

	/*Creacion de objetos
	-enemigos
	-cartas
	-personaje*/

	//Enemigos
	Enemigo enemigo1("Muneco", "Objeto de entrenamiento", 10, 5, 3);
	Enemigo enemigo2("Slime", "Ser hecho de baba apenas inteligente", 30, 20, 7);
	Enemigo enemigo3("Esqueleto", "Grupo de huesos reanimados, debil fisicamente", 20, 20, 14);
	Enemigo enemigo4("Lich", "Nigromante experto en magia", 20, 40, 10);
	Enemigo enemigo5("Caballero de la muerte", "Caballero no muerto, altamente peligroso", 40, 20, 20);
	Enemigo enemigo6("Guardia Infernal", "Ser demoniaco que custodia al rey lich", 30, 15, 30);
	Enemigo enemigo7("Rey Lich", "El oponente final, señor de la muerte", 50, 40, 20);

	//Cartas
	Carta Carta1("Ataque Basico", "Golpe sencillo de espada", "Fisico", 1, 3, 2, false); 
	Carta Carta2("Embestida", "Carga contra un oponente", "Fisico", 2, 5, 5, false);
	Carta Carta3("Corte Giratorio", "Gira para cortar al enemigo", "Fisico", 3, 8, 10, false); 
	Carta Carta4("Apuñalada", "Atraviesa a un enemigo", "Fisico", 4, 10, 12, false);
	Carta Carta5("Corte Doble", "Corta a un enemigo dos veces", "Fisico", 5, 6, 10, false);
	Carta Carta6("Ejecucion", "Ejecuta a un enemigo", "Fisico", 6, 25, 25, false);
	Carta Carta7("Descarga Magica", "Disparo de magia", "Magico", 7, 3, 3, false);
	Carta Carta8("Trueno", "Descarga electrica aerea", "Magico", 8, 6, 7, false);
	Carta Carta9("Escarcha", "Rafaga de fragmentos helados", "Magico", 9, 10, 8, false);
	Carta Carta10("Quemadura", "Explosion de fuego", "Magico", 10, 12, 10, false);
	Carta Carta11("Explosion Oscura", "Explosion de eneriga  oscura","Magico", 11, 16, 12, false);
	Carta Carta12("Luz Sagrada", "Descarga de una luz divina","Magico", 12, 30, 30, false);
	Carta Carta13("Cura", "Magia sanadora basica", "Soporte", 13, 0, 10, false);
	Carta Carta14("Bloqueo", "Bloquea el siguiente ataque", "Soporte", 14, 0, 10, false);
	Carta Carta15("Lectura", "Revela los siguientes movimientos del rival", "Soporte", 15, 0, 20, false);
	Carta Carta16("Regeneracion", "Regenera la vida gradualmente cada turno", "Soporte", 16, 0, 20, false);
	Carta Carta17("Concentracion", "Incrementa el daño de todas las cartas en el siguiente turno", "Soporte", 17, 0, 25, false);
	Carta Carta18("Resurrecion", "Revive una vez tras morir", "Soporte", 18, 0, 30, false);
	
	//Personaje
	Personaje Protagonista("Caballero", 100, 50);
	mazo_total.push_back(Carta1);
	mazo_total.push_back(Carta2);
	mazo_total.push_back(Carta3);
	mazo_total.push_back(Carta4);
	mazo_total.push_back(Carta5);
	mazo_total.push_back(Carta6);
	mazo_total.push_back(Carta7);
	mazo_total.push_back(Carta8);
	mazo_total.push_back(Carta9);
	mazo_total.push_back(Carta10);
	mazo_total.push_back(Carta11);
	mazo_total.push_back(Carta12);
	mazo_total.push_back(Carta13);
	mazo_total.push_back(Carta14);
	mazo_total.push_back(Carta15);
	mazo_total.push_back(Carta16);
	mazo_total.push_back(Carta17);
	mazo_total.push_back(Carta18);
	tutorial();

}

void Cartas_mazo()
{
	int opcion = 0;
	do {
		limpiarPantalla();
		cout << "Por favor cree un mazo con un maximo de 12 cartas" << endl << endl << "Cartas:" << endl;
		int j = 4;
		for (auto i = mazo_total.begin(); i != mazo_total.end(); i++)
		{

			cout << i->get_ID() << "-" << "[" << i->get_Nombre() << "]" << " ";
			if ((j + 1) % 4 == 0)
			{
				cout << endl;
			};
			j++;
		}
		cout << endl << "Mazo Actual:" << endl;
		int l = 4;
		for (auto k = mazo_actual.begin(); k != mazo_actual.end(); k++)
		{

			cout << "[" << k->get_Nombre() << "]" << " ";
			if ((l+1) % 4 == 0)
			{
				cout << endl;
			};
			l++;
		}

		cout << endl << "Ingrese una opcion" << endl << "1- Añadir Carta al mazo" << endl << "2- Eliminar Carta del mazo" << endl << "3-Ordenar Mazo" << endl << "4- Salir"<< endl << "Opcion:";
		cin >> opcion;
		if (opcion == 1)
		{
			int seleccion;
			cout << endl << "Seleccione la ID de la carta:";
			cin >> seleccion;

			bool encontrada = false;

			for (auto& carta : mazo_actual)
			{
				if (seleccion == carta.get_ID())
				{
					encontrada = true;
					break;
				}
			}

			if (!encontrada)
			{
				for (auto m = mazo_total.begin(); m != mazo_total.end(); m++)
				{
					if (seleccion == m->get_ID())
					{
						mazo_actual.push_back(move(*m));
						break;
					}
				}
			}
			
		}

		if (opcion == 2)
		{

			int seleccion;
			cout << endl << "Seleccione la ID de la carta:";
			cin >> seleccion;

			
			for (auto n = mazo_actual.begin(); n != mazo_total.end(); n++)
			{
				if (seleccion == n->get_ID())
				{
					mazo_total.insert(n, move(*n));
				}

			}

		}
	} while (opcion != 4);
};

void tutorial()
{
	//Inicio de la aventura
	cout << "|Dungeons and Cards (creado por Nantendo)|" << endl << "Bienvenido Caballero, ante ti se encuentra una gran mazmorra" << endl << "Dentro toda clase de peligros te esperan, junto a grandes tesoros" << endl << "Para salir vivo de tu mision, deberas usar una serie de cartas magicas" << endl << "Necesitas de mi guia, o te aventuraras solo por tu cuenta?" << endl;
	int opcion = 0;
	bool terminar = false;
	do
	{

		cout << "Ingrese una opcion" << endl << "1- Escuchar la explicacion" << endl << "2- Continuar sin tutorial" << endl << "Opcion:";
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
	} while (terminar == false);
	Menu();
};