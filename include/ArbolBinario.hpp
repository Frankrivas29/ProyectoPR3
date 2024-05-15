#ifndef ARBOLBINARIO_HPP
#define ARBOLBINARIO_HPP

#include "Cartas.hpp"
#include "Enemigos.hpp"

class ArbolBinario {
public:
	class NodoArbol {
	public:
		Carta carta;
		int dano_enemigo;
		int costo_total;
		NodoArbol* izquierda;
		NodoArbol* derecha;

		NodoArbol(const Carta& carta) : carta(carta), izquierda(nullptr), derecha(nullptr) {}
	};

	ArbolBinario();
	void insertar(const Carta& carta, const Enemigo& enemigo);
	/* void imprimirDerecha() const;
	 void imprimirDerechaRecursivo(NodoArbol* nodo) const;*/
	void Calcular_dano_recursivo(NodoArbol* nodo, int& dano_enemigo) const;
	int Calcular_dano() const;
	void Calcular_costo_recursivo(NodoArbol* nodo, int& costo_total) const;
	int Calcular_costo() const;
	void limpiarArbol(NodoArbol* nodo);
	void limpiarArbol();


private:
	NodoArbol* raiz;
	NodoArbol* insertarRecursivo(NodoArbol* nodo, const Carta& carta, const Enemigo& enemigo);
};

#endif // ARBOLBINARIO_HPP