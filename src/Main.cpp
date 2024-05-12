#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>
#include <Enemigos.hpp>
#include <Cartas.hpp>
#include <random> 
#include <Personaje.hpp>

using namespace std;

//Datos

vector <Carta> mazo_total;
vector <Carta> mazo_actual;
vector <Enemigo> enemigos;
vector <Carta> mazo_combate;
vector <Carta> mazo_ataques;
static int opcion = 0;
static int contador_enemigos = 1;
//Personaje
Personaje Protagonista("Caballero", 100, 50);


//Declaracion de funciones

void tutorial();
void Menu();
void pausa();
void limpiarPantalla();
void Cartas_mazo();
void manual();
void combate();
void atacar();

//Main

int main()

{
	/*Creacion de objetos
	-enemigos
	-cartas
	-personaje*/

	//Enemigos
	Enemigo enemigo1("Muneco", "Objeto de entrenamiento",1, 10, 5, 3);
	Enemigo enemigo2("Slime", "Ser hecho de baba apenas inteligente",2, 30, 20, 7);
	Enemigo enemigo3("Esqueleto", "Grupo de huesos reanimados, debil fisicamente",3, 20, 20, 14);
	Enemigo enemigo4("Lich", "Nigromante experto en magia",4, 20, 40, 10);
	Enemigo enemigo5("Caballero de la muerte", "Caballero no muerto, altamente peligroso",5, 40, 20, 20);
	Enemigo enemigo6("Guardia Infernal", "Ser demoniaco que custodia al rey lich",6, 30, 15, 30);
	Enemigo enemigo7("Rey Lich", "El oponente final, señor de la muerte",7, 50, 40, 20);

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
	Carta Carta19("Tiro con arco", "Dispara una flecha a toda velocidad","Distancia", 19, 5, 7, false);
	Carta Carta20("Disparo triple", "Dispara tres flechas a la vez", "Distancia", 20, 12, 8, false);
	Carta Carta21("Flecha ignea", "Dispara una flecha de fuego", "Distancia", 21, 15, 9, false);
	Carta Carta22("Flecha helada", "Dispara una flecha de hielo", "Distancia", 22, 16, 10, false);
	Carta Carta23("Flechas divinas", "Dispara flechas imbuidas en luz sagrada", "Distancia", 23, 18, 14, false);
	Carta Carta24("Lluvia de flechas", "Dispara cientos de flechas en una lluvia mortal", "Distancia", 24, 30, 30, false);
	Carta Carta25("null", "null", "null", 0, 0, 0, false);
	


	//Estructuras de datos
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
	mazo_total.push_back(Carta19);
	mazo_total.push_back(Carta20);
	mazo_total.push_back(Carta21);
	mazo_total.push_back(Carta22);
	mazo_total.push_back(Carta23);
	mazo_total.push_back(Carta24);

	enemigos.push_back(enemigo1);
	enemigos.push_back(enemigo2);
	enemigos.push_back(enemigo3);
	enemigos.push_back(enemigo4);
	enemigos.push_back(enemigo5);
	enemigos.push_back(enemigo6);
	enemigos.push_back(enemigo7);

	mazo_ataques.push_back(Carta25);
	mazo_ataques.push_back(Carta25);
	mazo_ataques.push_back(Carta25);
	mazo_ataques.push_back(Carta25);


	//Inicio
	tutorial();

}

//Pausa

void pausa() {
	cout << "Presione enter para continuar";
	cin.ignore(); // Ignora la entrada anterior (el Enter)
	cin.get();    // Espera a que se presione Enter nuevamente
};

//Limpiar pantalla

void limpiarPantalla() {
	system("clear"); // Limpia la pantalla en sistemas Unix/Linux
};

//Manual

void manual()
{
	limpiarPantalla();
	cout << "|Manual|" << endl << "1- Tendras un mazo disponible, con un total de 12 cartas" << endl << "2- cada turno recibiras 4 cartas, podras jugarlas todas o ninguna" << endl << "3- cada carta tiene un valor de daño, y un coste" << endl << "4- tu energia es limitada, solo podras usar cartas cuyo coste sea menor a tu energia" << endl << "5- si combinas cartas del mismo tipo, el daño se duplica" << endl << "6- si el enemigo y tu juegan cartas iguales, se cancelan" << endl << "7- Deberas de derrotar a tu enemigo usando las cartas disponibles" << endl << endl << "Buena suerte!" << endl;
	pausa();
	limpiarPantalla();
	Menu();
}

//Menu

void Menu()
{


	do
	{
		cout << "|Dungeon and Cards|" << endl << "|Menu|" << endl << "|1| Entrar a la mazmorra" << endl << "|2| Creacion del mazo" << endl << "|3| Instrucciones" << endl << "|4| Salir" << endl;
		cout << "Ingrese una opcion" << endl;
		cin >> opcion;

		if (opcion == 1)
		{
			if (mazo_actual.size() <= 0)
			{
				cout << "necesitas al menos una carta para jugar" << endl;
				pausa();
				limpiarPantalla();
				Menu();
			}

			else
			{
				cout << "Ante ti esta el primer oponente, un muñeco de entrenamiento basico" << endl;
				combate();
			}
		}

		else if (opcion == 2)
		{
			Cartas_mazo();
		}

		else if (opcion == 3)
		{
			manual();
		}

		else if (opcion == 4)
		{
			cout << "Esperamos que hayas disfrutado de tu aventura, adios..." << endl;
			break;
		}

	}

	while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4);
}

//Mazo

void Cartas_mazo()
{
	int opcion = 0;
	do {
		limpiarPantalla();
		cout << "Por favor cree un mazo con un maximo de 12 cartas" << endl << endl << "Cartas:" << endl;
		int j = 4;

		for (auto i = mazo_total.begin(); i != mazo_total.end(); i++) 
		{
			if (!i->get_Nombre().empty()) 
			{ 
				cout << i->get_ID() << "-" << "[" << i->get_Nombre() << "]" << " ";
				if ((j + 1) % 4 == 0) {
					cout << endl;
				}
				j++;
			}
		}
		
		cout << endl << endl << "Mazo Actual:" << endl;
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

		cout << endl << endl << "Ingrese una opcion" << endl << "1- Añadir Carta al mazo" << endl << "2- Eliminar Carta del mazo" << endl << "3- Datos" << endl << "4- Salir"<< endl << "Opcion:";
		cin >> opcion;
		if (opcion == 1)
		{
			if(mazo_actual.size() <12)
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
						mazo_actual.back().set_ID_original(seleccion); 
						mazo_total.erase(m);
						break;
					}
				}
			}
			
			}
			else
			{
				cout << "se ha excedido el tamaño maximo" << endl;
				pausa();

			}
		}

		if(opcion == 2) 
		{
			int seleccion;
			cout << endl << "Seleccione la ID de la carta:";
			cin >> seleccion;

			// Buscar la carta en el mazo actual y eliminarla
			auto it = find_if(mazo_actual.begin(), mazo_actual.end(), [seleccion](const Carta& carta) 
				{
				return carta.get_ID() == seleccion;
				});

			if (it != mazo_actual.end())
			{
				// Obtener la posición de la carta en el mazo actual
				int posicion = distance(mazo_actual.begin(), it);

				// Guardar la carta en una variable temporal
				Carta carta_eliminada = move(*it);

				// Eliminar la carta del mazo actual
				mazo_actual.erase(it);

				// Encontrar la posición original de la carta en el mazo total
				auto it_total = mazo_total.begin() + carta_eliminada.get_ID() - 1;

				// Insertar la carta en su posición original en el mazo total
				mazo_total.insert(it_total, move(carta_eliminada));

				// Imprimir en la posición correspondiente
				int j = 4;
				for (const auto& carta : mazo_total) {
					cout << carta.get_ID() << "-" << "[" << carta.get_Nombre() << "]" << " ";
					if ((j + 1) % 4 == 0) {
						cout << endl;
					}
					j++;
				}
				cout << endl;
			}
			
		}
		
		if (opcion == 3) 
		{
			int seleccion;
			cout << endl << "Seleccione la ID de la carta:";
			cin >> seleccion;
			bool cartaEncontrada = false;

			// Buscar en mazo_total
			for (const auto& carta : mazo_total) 
			{
				if (seleccion == carta.get_ID()) 
				{
					cout << "Nombre: " << carta.get_Nombre() << endl
						<< "Descripcion: " << carta.get_Descripcion() << endl
						<< "Daño: " << carta.get_Dano() << endl
						<< "Coste: " << carta.get_Coste() << endl;
					cartaEncontrada = true;
					pausa();
					break;
				}
			}

			// Si la carta no se encontró en mazo_total, buscar en mazo_actual
			if (!cartaEncontrada) 
			{
				for (const auto& carta : mazo_actual) 
				{
					if (seleccion == carta.get_ID_original()) { // Usar ID_original para buscar la carta
						cout << "Nombre: " << carta.get_Nombre() << endl
							<< "Descripcion: " << carta.get_Descripcion() << endl
							<< "Daño: " << carta.get_Dano() << endl
							<< "Coste: " << carta.get_Coste() << endl;
						cartaEncontrada = true;
						pausa();
						break;
					}
				}
			}

			// Si la carta no se encuentra en ninguno de los dos vectores
			if (!cartaEncontrada) 
			{
				cout << "Carta no encontrada" << endl;
				pausa();
			}
		}
		
	

	} while (opcion != 4);
	limpiarPantalla();
	Menu();
};

//Tutorial

void tutorial()
{
	//Inicio de la aventura
	cout << "|Dungeons and Cards (creado por Nantendo)|" << endl << "Bienvenido Caballero, ante ti se encuentra una gran mazmorra" << endl << "Dentro toda clase de peligros te esperan, junto a grandes tesoros" << endl << "Para salir vivo de tu mision, deberas usar una serie de cartas magicas" << endl << "Necesitas de mi guia, o te aventuraras solo por tu cuenta?" << endl << endl;
	int opcion = 0;
	bool terminar = false;
	do
	{

		cout << "Ingrese una opcion" << endl << "1- Escuchar la explicacion" << endl << "2- Continuar sin tutorial" << endl << "Opcion:";
		cin >> opcion;
		limpiarPantalla();
		if (opcion == 1)
		{

			manual();			
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

void combate()
{
	//llenar mazo de combate
	mazo_combate = mazo_actual;

	limpiarPantalla();
	for (const auto& enemigo : enemigos)
	{
		if (contador_enemigos == enemigo.get_ID())
		{
			
		cout  << "|La Mazmorra|" << endl << endl  << "||Oponente||"  << endl << "Nombre: " << enemigo.get_Nombre() << endl << "Descripcion: " << enemigo.get_Descripcion() << endl << "Vida: " << enemigo.get_Vida() << endl << "Dano: " << enemigo.get_Dano() << endl
		<< endl <<"||Jugador||"<< endl  << "Nombre:" << Protagonista.get_Nombre() << endl << "Vida:" << Protagonista.get_Vida() << endl << "Enegia:" << Protagonista.get_Energia() << endl;
 		
		cout << endl << " |||Jugada actual:||| " << endl << "[";
			
		for (const auto& carta : mazo_ataques)
		{
			if (carta.get_ID() == 0)
			{
				cout << " * ";
			}
		};
			
		cout << "]" << endl;

		cout << "||-Mazo-||"

		if (enemigo.get_Vida() == 0)
		{
			cout << "El:" << enemigo.get_Nombre() << "ha sido derrotado, regresa a la entrada y preparate para tu siguiente combate" << endl;
			contador_enemigos++;
			Menu();

		}


		}
		
	}
}