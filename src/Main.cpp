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
#include <ArbolBinario.hpp>

using namespace std;

/*Creacion de objetos
	-enemigos
	-cartas
	-personaje*/

	//Enemigos
Enemigo enemigo1("Muneco", "Objeto de entrenamiento", 1, 20, 7, 1, 0, 0);
Enemigo enemigo2("Slime", "Ser hecho de baba apenas inteligente", 2, 70, 20, 2, 0, 0);
Enemigo enemigo3("Esqueleto", "Grupo de huesos reanimados, debil fisicamente", 3, 60, 20, 4, 0, 0);
Enemigo enemigo4("Lich", "Nigromante experto en magia", 4, 100, 60, 10, 0, 0);
Enemigo enemigo5("Caballero de la muerte", "Caballero no muerto, altamente peligroso", 5, 120, 60, 5, 0, 0);
Enemigo enemigo6("Guardia Infernal", "Ser demoniaco que custodia al rey lich", 6, 125, 115, 5, 0, 0);
Enemigo enemigo7("Rey Lich", "El oponente final, señor de la muerte", 7, 150, 140, 6, 0, 0);

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
Carta Carta11("Explosion Oscura", "Explosion de eneriga  oscura", "Magico", 11, 16, 12, false);
Carta Carta12("Luz Sagrada", "Descarga de una luz divina", "Magico", 12, 30, 30, false);
Carta Carta13("Cura", "Magia sanadora basica", "Soporte", 13, 0, 10, false);
Carta Carta14("Bloqueo", "Bloquea el siguiente ataque", "Soporte", 14, 0, 10, false);
Carta Carta15("Cura Media", "Magia Sanadora Avanazada", "Soporte", 15, 0, 20, false);
Carta Carta16("Regeneracion", "Regenera la vida gradualmente cada turno", "Soporte", 16, 0, 20, false);
Carta Carta17("Concentracion", "Incrementa el daño de todas las cartas en el siguiente turno", "Soporte", 17, 0, 25, false);
Carta Carta18("Restauracion", "Restaura todo los daños", "Soporte", 18, 0, 30, false);
Carta Carta19("Tiro con arco", "Dispara una flecha a toda velocidad", "Distancia", 19, 5, 7, false);
Carta Carta20("Disparo triple", "Dispara tres flechas a la vez", "Distancia", 20, 12, 8, false);
Carta Carta21("Flecha ignea", "Dispara una flecha de fuego", "Distancia", 21, 15, 9, false);
Carta Carta22("Flecha helada", "Dispara una flecha de hielo", "Distancia", 22, 16, 10, false);
Carta Carta23("Flechas divinas", "Dispara flechas imbuidas en luz sagrada", "Distancia", 23, 18, 14, false);
Carta Carta24("Lluvia de flechas", "Dispara cientos de flechas en una lluvia mortal", "Distancia", 24, 30, 30, false);

ArbolBinario AI_1;
ArbolBinario AI_2;
ArbolBinario AI_3;
ArbolBinario AI_4;
ArbolBinario AI_5;
ArbolBinario AI_6;
ArbolBinario AI_7;

//Datos

vector <Carta> mazo_total;
vector <Carta> mazo_actual;
vector <Enemigo> enemigos;
vector <Carta> mazo_combate;
vector <Carta> mazo_ataques_vacio;
vector <Carta> mazo_ataques;

vector<Carta> movimientos_enemigos1;
vector<Carta> movimientos_enemigos2;
vector<Carta> movimientos_enemigos3;
vector<Carta> movimientos_enemigos4;
vector<Carta> movimientos_enemigos5;
vector<Carta> movimientos_enemigos6;
vector<Carta> movimientos_enemigos7;

vector<ArbolBinario> IAs_enemigos;

static int contador_enemigos = 1;
static int contador_cartas = 0;
static int dano_total;
static int cooldown_cartas = 0;
static int cooldown_regeneracion = 0;
static int cooldown_concentracion = 0;
static int cooldown_bloqueo = 0;
static bool bloqueo_activo = false;
static bool regeneracion_activo = false;
static bool concentracion_activa = false;
const int turnos_regeneracion = 5;
const int turnos_concentracion = 2;
const int turnos_para_reutilizar_cartas = 2;

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
void Carta_Efectos();
void ataque_enemigo();
void Ordenar_IA();

//Main

int main()

{

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

	movimientos_enemigos1.push_back(Carta1);
	movimientos_enemigos1.push_back(Carta1);


	movimientos_enemigos2.push_back(Carta1);
	movimientos_enemigos2.push_back(Carta2);
	movimientos_enemigos2.push_back(Carta3);

	movimientos_enemigos3.push_back(Carta1);
	movimientos_enemigos3.push_back(Carta2);
	movimientos_enemigos3.push_back(Carta3);
	movimientos_enemigos3.push_back(Carta4);
	movimientos_enemigos3.push_back(Carta5);

	movimientos_enemigos4.push_back(Carta7);
	movimientos_enemigos4.push_back(Carta8);
	movimientos_enemigos4.push_back(Carta9);
	movimientos_enemigos4.push_back(Carta10);
	movimientos_enemigos4.push_back(Carta11);

	movimientos_enemigos5.push_back(Carta3);
	movimientos_enemigos5.push_back(Carta4);
	movimientos_enemigos5.push_back(Carta6);
	movimientos_enemigos5.push_back(Carta24);

	movimientos_enemigos6.push_back(Carta6);
	movimientos_enemigos6.push_back(Carta6);
	movimientos_enemigos6.push_back(Carta11);
	movimientos_enemigos6.push_back(Carta10);

	movimientos_enemigos7.push_back(Carta2);
	movimientos_enemigos7.push_back(Carta5);
	movimientos_enemigos7.push_back(Carta8);
	movimientos_enemigos7.push_back(Carta10);
	movimientos_enemigos7.push_back(Carta11);
	movimientos_enemigos7.push_back(Carta12);
	movimientos_enemigos7.push_back(Carta6);

	//Inicio
	limpiarPantalla();
	tutorial();

}

//Ordenar la "IA" del enemigo
void Ordenar_IA()
{

	if (contador_enemigos == 1)
	{
		for (const auto& movimiento : movimientos_enemigos1)
		{
			AI_1.limpiarArbol();
			AI_1.insertar(movimiento, enemigo1);


		}
	}

	else if (contador_enemigos == 2)
	{
		for (const auto& movimiento : movimientos_enemigos2)
		{
			AI_2.limpiarArbol();
			AI_2.insertar(movimiento, enemigo2);


		}
	}

	else if (contador_enemigos == 3)
	{
		for (const auto& movimiento : movimientos_enemigos3)
		{
			AI_3.limpiarArbol();
			AI_3.insertar(movimiento, enemigo3);


		}
	}


	else if (contador_enemigos == 4)
	{
		for (const auto& movimiento : movimientos_enemigos4)
		{
			AI_4.limpiarArbol();
			AI_4.insertar(movimiento, enemigo4);


		}
	}


	else if (contador_enemigos == 5)
	{
		for (const auto& movimiento : movimientos_enemigos5)
		{
			AI_5.limpiarArbol();
			AI_5.insertar(movimiento, enemigo5);


		}
	}


	else if (contador_enemigos == 6)
	{
		for (const auto& movimiento : movimientos_enemigos6)
		{
			AI_6.limpiarArbol();
			AI_6.insertar(movimiento, enemigo6);


		}
	}


	else if (contador_enemigos == 7)
	{
		for (const auto& movimiento : movimientos_enemigos7)
		{
			AI_7.limpiarArbol();
			AI_7.insertar(movimiento, enemigo7);


		}
	}
}

//Funcion de ataque

void ataque_enemigo() {
	if (contador_enemigos == 1) {
		int dano_enemigo = AI_1.Calcular_dano();
		enemigo1.set_Dano_total(dano_enemigo + enemigo1.get_Dano());
		Protagonista.set_Vida(Protagonista.get_Vida() - enemigo1.get_Dano_total());
	}
	else if (contador_enemigos == 2) {
		int dano_enemigo = AI_2.Calcular_dano();
		enemigo2.set_Dano_total(dano_enemigo + enemigo2.get_Dano());
		Protagonista.set_Vida(Protagonista.get_Vida() - enemigo2.get_Dano_total());
	}
	else  if (contador_enemigos == 3) {
		int dano_enemigo = AI_3.Calcular_dano();
		enemigo3.set_Dano_total(dano_enemigo + enemigo3.get_Dano());
		Protagonista.set_Vida(Protagonista.get_Vida() - enemigo3.get_Dano_total());
	}
	else if (contador_enemigos == 4) {
		int dano_enemigo = AI_4.Calcular_dano();
		enemigo4.set_Dano_total(dano_enemigo + enemigo4.get_Dano());
		Protagonista.set_Vida(Protagonista.get_Vida() - enemigo4.get_Dano_total());
	}
	else if (contador_enemigos == 5) {
		int dano_enemigo = AI_5.Calcular_dano();
		enemigo5.set_Dano_total(dano_enemigo + enemigo5.get_Dano());
		Protagonista.set_Vida(Protagonista.get_Vida() - enemigo5.get_Dano_total());
	}
	else if (contador_enemigos == 6) {
		int dano_enemigo = AI_6.Calcular_dano();
		enemigo6.set_Dano_total(dano_enemigo + enemigo6.get_Dano());
		Protagonista.set_Vida(Protagonista.get_Vida() - enemigo6.get_Dano_total());
	}

	else if (contador_enemigos == 7) {
		int dano_enemigo = AI_7.Calcular_dano();
		enemigo7.set_Dano_total(dano_enemigo + enemigo7.get_Dano());
		Protagonista.set_Vida(Protagonista.get_Vida() - enemigo7.get_Dano_total());
	}
}


//Pausa

void pausa() {
	cout << "Presione enter para continuar";
	cin.ignore(); 
	cin.get();    
};

//Limpiar pantalla

void limpiarPantalla() {
	system("clear"); 
};

//Manual

void manual()
{
	limpiarPantalla();
	cout << "|Manual|" << endl << "1- Tendras un mazo disponible, con un total de 12 cartas" << endl << "2- cada turno recibiras varias cartas, podras jugar un maximo de 4" << endl << "3- cada carta tiene un valor de daño, y un coste" << endl << "4- tu energia es limitada, solo podras usar cartas cuyo coste sea menor a tu energia" << endl << "5- si combinas cartas del mismo tipo, el daño se duplica" << endl << "6- Cada turno recuperadas parte de tu energia" << endl << "7- Deberas de derrotar a tu enemigo usando las cartas disponibles" << endl << endl << "Buena suerte!" << endl;
	pausa();
	limpiarPantalla();
	Menu();
}

//Menu

void Menu()
{

	int opcion_menu = 0;
	do
	{

		cout << "|Dungeon and Cards|" << endl << "|Menu|" << endl << "|1| Entrar a la mazmorra" << endl << "|2| Creacion del mazo" << endl << "|3| Instrucciones" << endl << "|4| Salir" << endl;
		cout << "Ingrese una opcion" << endl;
		cin >> opcion_menu;

		if (opcion_menu == 1)
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
				combate();
			}
		}

		else if (opcion_menu == 2)
		{
			Cartas_mazo();
		}

		else if (opcion_menu == 3)
		{
			manual();
		}

		else if (opcion_menu == 4)
		{
			cout << "Esperamos que hayas disfrutado de tu aventura, adios..." << endl;
			break;
		}

	}

	while (opcion_menu != 1 && opcion_menu != 2 && opcion_menu != 3 && opcion_menu != 4);
}

//Mazo

void Cartas_mazo()
{
	int opcion_mazo = 0;
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
			if ((l + 1) % 4 == 0)
			{
				cout << endl;
			};
			l++;
		}

		cout << endl << endl << "Ingrese una opcion" << endl << "1- Añadir Carta al mazo" << endl << "2- Eliminar Carta del mazo" << endl << "3- Datos" << endl << "4- Salir" << endl << "Opcion:";
		cin >> opcion_mazo;
		if (opcion_mazo == 1)
		{
			if (mazo_actual.size() < 12)
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

		if (opcion_mazo == 2)
		{
			int seleccion;
			cout << endl << "Seleccione la ID de la carta:";
			cin >> seleccion;
			auto it = find_if(mazo_actual.begin(), mazo_actual.end(), [seleccion](const Carta& carta)
				{
					return carta.get_ID() == seleccion;
				});

			if (it != mazo_actual.end())
			{
				int posicion = distance(mazo_actual.begin(), it);
				Carta carta_eliminada = move(*it);
				mazo_actual.erase(it);
				auto it_total = mazo_total.begin() + carta_eliminada.get_ID() - 1;
				mazo_total.insert(it_total, move(carta_eliminada));
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

		if (opcion_mazo == 3)
		{
			int seleccion;
			cout << endl << "Seleccione la ID de la carta:";
			cin >> seleccion;
			bool cartaEncontrada = false;
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
			if (!cartaEncontrada)
			{
				for (const auto& carta : mazo_actual)
				{
					if (seleccion == carta.get_ID_original())
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
			}
			if (!cartaEncontrada)
			{
				cout << "Carta no encontrada" << endl;
				pausa();
			}
		}



	} while (opcion_mazo != 4);
	limpiarPantalla();
	Menu();
};

//Tutorial

void tutorial()
{
	//Inicio de la aventura
	cout << "|Dungeons and Cards (creado por Nantendo)|" << endl << "Bienvenido Caballero, ante ti se encuentra una gran mazmorra" << endl << "Dentro toda clase de peligros te esperan, junto a grandes tesoros" << endl << "Para salir vivo de tu mision, deberas usar una serie de cartas magicas" << endl << "Necesitas de mi guia, o te aventuraras solo por tu cuenta?" << endl << endl;
	int opcion_tutorial = 0;
	bool terminar = false;
	do
	{

		cout << "Ingrese una opcion" << endl << "1- Escuchar la explicacion" << endl << "2- Continuar sin tutorial" << endl << "Opcion:";
		cin >> opcion_tutorial;
		limpiarPantalla();
		if (opcion_tutorial == 1)
		{

			manual();
			pausa();
			limpiarPantalla();
			terminar = true;
		}

		else if (opcion_tutorial == 2)
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

//combate

void combate()
{

	mazo_combate = mazo_actual;
	mazo_ataques.clear();
	int opcion_combate = 0;
	random_device rd;
	mt19937 g(rd());
	shuffle(mazo_combate.begin(), mazo_combate.end(), g);

	if (Protagonista.get_Vida() > 0)
	{
		for (auto k = enemigos.begin(); k != enemigos.end(); k++)
		{


			do
			{

				limpiarPantalla();

				if (contador_enemigos == k->get_ID())
				{

					cout << "|La Mazmorra|" << endl << endl << "||-Oponente-||" << endl << "Nombre: " << k->get_Nombre() << endl << "Descripcion: " << k->get_Descripcion() << endl << "Vida: " << k->get_Vida() << endl << "Dano: " << k->get_Dano() << endl << "Energia: " << k->get_Energia() << endl
						<< endl << "||-Jugador-||" << endl << "Nombre:" << Protagonista.get_Nombre() << endl << "Vida:" << Protagonista.get_Vida() << endl << "Enegia:" << Protagonista.get_Energia() << endl;

					cout << endl << " ||-Jugada actual:-|| " << endl << "[";

					for (const auto& carta : mazo_ataques)
					{

						cout << " " << carta.get_Nombre() << " ";

					};

					cout << "]" << endl << endl;

					cout << "||-Mazo-||" << endl << "Cartas disponibles:" << "[ ";

					for (auto m = mazo_combate.begin(); m != mazo_combate.end(); m++)
					{
						if (contador_cartas < 4)
						{
							cout << m->get_ID_original() << "-" << " " << m->get_Nombre() << " ";
						};
						contador_cartas++;
					}
					cout << "]" << endl;

					//opciones

					cout << endl << "||-Opciones-||" << endl << "|1-| Escoger una carta" << endl << "|2-| Retirar una carta" << endl << "|3-| Finalizar turno" << endl << "|4-| Huir" << endl;
					cin >> opcion_combate;
					contador_cartas = 0;

					if (opcion_combate == 1) {
						if (mazo_ataques.size() < 4) {
							int seleccion;
							cout << endl << "Seleccione la ID de la carta:";
							cin >> seleccion;

							bool encontrada = false;
							int costoTotal = 0;

							for (const auto& carta : mazo_ataques) {
								costoTotal += carta.get_Coste();
							}

							for (const auto& carta : mazo_combate) {
								if (seleccion == carta.get_ID()) {
									costoTotal += carta.get_Coste();

									if (carta.get_Usada()) {
										cout << "Esta carta ya ha sido usada en este turno. Debes esperar para usarla de nuevo." << endl;
										pausa();
										break;
									}
								}
							}

							if (Protagonista.get_Energia() - costoTotal >= 0) {
								for (auto m = mazo_combate.begin(); m != mazo_combate.end(); m++) {
									if (seleccion == m->get_ID() && !m->get_Usada()) {
										mazo_ataques.push_back(move(*m));
										mazo_ataques.back().set_ID_original(seleccion);
										mazo_combate.erase(m);
										break;
									}
								}
							}
							else {
								cout << "No tienes suficiente energía para usar esta carta." << endl;
								pausa();
							}
						}
						else {
							cout << "Se ha excedido el tamaño máximo de cartas en el mazo de ataques." << endl;
							pausa();
						}
					}



					if (opcion_combate == 2)

					{

						int seleccion;
						cout << endl << "Seleccione la ID de la carta:";
						cin >> seleccion;

						bool encontrada = false;

						for (auto& carta : mazo_combate)
						{
							if (seleccion == carta.get_ID())
							{
								encontrada = true;
								break;
							}
						}

						if (!encontrada)
						{
							for (auto m = mazo_ataques.begin(); m != mazo_ataques.end(); m++)
							{
								if (seleccion == m->get_ID())
								{

									mazo_combate.push_back(move(*m));
									mazo_combate.back().set_ID_original(seleccion);
									mazo_ataques.erase(m);
									break;
								}
							}
						}


					}


					if (opcion_combate == 3)
					{
						atacar();


						if (regeneracion_activo == true)
						{
							Protagonista.set_Vida(Protagonista.get_Vida() + 15);
							cooldown_regeneracion++;

							if (cooldown_regeneracion >= turnos_regeneracion)
							{
								regeneracion_activo = false;
								cooldown_regeneracion = 0;
							}
						}

						if (concentracion_activa == true)
						{
							cooldown_concentracion++;

							if (cooldown_concentracion >= turnos_concentracion)
							{
								concentracion_activa = false;
								cooldown_concentracion = 0;
							}
						}

						if (bloqueo_activo == true)
						{
							cooldown_bloqueo++;
							if (cooldown_bloqueo >= turnos_para_reutilizar_cartas)
							{
								bloqueo_activo = false;
								cooldown_bloqueo = 0;
							}
						}

						Protagonista.set_Energia(Protagonista.get_Energia() + 25);

						pausa();

						k->set_Vida(k->get_Vida() - dano_total);
						dano_total = 0;
						for (auto& carta : mazo_ataques) {
							carta.set_Usada(false);
						}

						cooldown_cartas++;
						if (cooldown_cartas >= turnos_para_reutilizar_cartas) {
							for (auto& carta : mazo_combate) {
								carta.set_Usada(false);
							}
							cooldown_cartas = 0;
						}

						if (bloqueo_activo == false)
						{
							if (k->get_Energia() > 0)
							{
								Ordenar_IA();
								ataque_enemigo();
								int costo_total_enemigo = 0;
								if (contador_enemigos == 1)
								{
									costo_total_enemigo = AI_1.Calcular_costo();
								}
								else if (contador_enemigos == 2)
								{
									costo_total_enemigo = AI_2.Calcular_costo();
								}
								else if (contador_enemigos == 3)
								{
									costo_total_enemigo = AI_3.Calcular_costo();
								}

								else if (contador_enemigos == 4)
								{
									costo_total_enemigo = AI_4.Calcular_costo();
								}
								else if (contador_enemigos == 5)
								{
									costo_total_enemigo = AI_5.Calcular_costo();
								}
								else if (contador_enemigos == 6)
								{
									costo_total_enemigo = AI_6.Calcular_costo();
								}
								else if (contador_enemigos == 7)
								{
									costo_total_enemigo = AI_7.Calcular_costo();
								}

								k->set_Coste_total(costo_total_enemigo);


								k->set_Energia(k->get_Energia() - k->get_Coste_total());
								if (k->get_Energia() < 0)
								{
									k->set_Energia(0);

								}
								cout << "El enemigo ataca!" << endl;
								pausa();
							}
							else
							{
								cout << "el enemigo no hace nada" << endl;
								k->set_Energia(0);
								pausa();
							}
							k->set_Energia(k->get_Energia() + 5);

						}
						else
						{
							cout << "has bloqueado" << endl;
							pausa();
						}
					}


					if (opcion_combate == 4)
					{
						cout << "La mazmorra estara esperandote..." << endl;
						pausa();
						limpiarPantalla();
						Menu();
					}


					if (k->get_Vida() <= 0)
					{
						limpiarPantalla();
						cout << "El: " << k->get_Nombre() << " ha sido derrotado, regresa a la entrada y preparate para tu siguiente combate" << endl;
						contador_enemigos++;
						Protagonista.set_Vida(100);
						Protagonista.set_Energia(50);

						if (k->get_ID() == 7)
						{
							cout << "Felicidades, has  completado Dungeon and Cards" << endl << "Gracias por jugar" << endl;
							pausa();
							break;

						}
						pausa();
						limpiarPantalla();
						Menu();
						break;

					}

				}


			} while (opcion_combate != 4 && k->get_Vida() != 0 && k->get_Vida() > 0 && Protagonista.get_Vida() > 0);

			if (Protagonista.get_Vida() <= 0)
			{
				cout << "derrotado" << endl;
				break;
			}

		}
	}
	else if (Protagonista.get_Vida() <= 0)
	{
		cout << "Has perdido, buena suerte la proxima" << endl;
		pausa();


	}
}

//Atacar

void atacar() {
	if (mazo_ataques.empty()) {
		cout << "No haces nada!" << endl;
		return;
	}


	bool mismo_tipo = true;
	string primer_tipo = mazo_ataques.front().get_Tipo();
	for (const auto& carta : mazo_ataques) {
		if (carta.get_Tipo() != primer_tipo) {
			mismo_tipo = false;
			break;
		}
	}

	for (auto& carta : mazo_ataques) {

		dano_total += carta.get_Dano();

		if (carta.get_ID() >= 13 && carta.get_ID() <= 18)
		{
			Carta_Efectos();
		}

		Protagonista.set_Energia(Protagonista.get_Energia() - carta.get_Coste());
		carta.set_Usada(true);
		mazo_combate.push_back(move(carta));
	}

	if (mismo_tipo == true) {

		dano_total *= 2.5;
		cout << "Combo Critico" << endl;
	}

	if (concentracion_activa == true)
	{
		dano_total *= 1.2;
	}
	cout << "Tu daño total es:" << dano_total << endl;


	mazo_ataques.clear();
}

//Efectos de cartas especificas

void Carta_Efectos()
{

	for (auto m = mazo_ataques.begin(); m != mazo_ataques.end(); m++)
	{
		if (m->get_ID() == 13)
		{
			if (Protagonista.get_Vida() < 85)
			{
				Protagonista.set_Vida(Protagonista.get_Vida() + 15);
			}
			else
			{
				Protagonista.set_Vida(100);
			}
		}
		if (m->get_ID() == 14)
		{
			bloqueo_activo = true;
		}
		if (m->get_ID() == 15)
		{
			if (Protagonista.get_Vida() < 50)
			{
				Protagonista.set_Vida(Protagonista.get_Vida() + 50);
			}
			else
			{
				Protagonista.set_Vida(100);
			}
		}
		if (m->get_ID() == 16)
		{
			regeneracion_activo = true;
		}
		if (m->get_ID() == 17)
		{
			concentracion_activa = true;
		}
		if (m->get_ID() == 18)
		{
			Protagonista.set_Vida(100);
		}
	}
}

