#include "ArbolBinario.hpp"

ArbolBinario::ArbolBinario() {
	raiz = nullptr;
}

ArbolBinario::NodoArbol* ArbolBinario::insertarRecursivo(NodoArbol* nodo, const Carta& carta, const Enemigo& enemigo) {
	if (nodo == nullptr) {
		return new NodoArbol(carta);
	}
	if (carta.get_Coste() < enemigo.get_Energia()) {

		nodo->izquierda = insertarRecursivo(nodo->izquierda, carta, enemigo);
	}
	else {

		nodo->derecha = insertarRecursivo(nodo->derecha, carta, enemigo);
	}

	return nodo;
}




void ArbolBinario::insertar(const Carta& carta, const Enemigo& enemigo) {
	raiz = insertarRecursivo(raiz, carta, enemigo);



}

/*void ArbolBinario::imprimirDerecha() const {
	imprimirDerechaRecursivo(raiz);
}

void ArbolBinario::imprimirDerechaRecursivo(NodoArbol* nodo) const {
	if (nodo != nullptr) {
		// Imprime la carta en el nodo actual


		// Recorre el subárbol derecho
		imprimirDerechaRecursivo(nodo->derecha);
	}
}
*/
int ArbolBinario::Calcular_dano() const
{
	int dano_enemigo = 0;
	Calcular_dano_recursivo(raiz, dano_enemigo);
	return dano_enemigo;
}

void ArbolBinario::Calcular_dano_recursivo(NodoArbol* nodo, int& dano_enemigo) const {
	if (nodo != nullptr) {
		Calcular_dano_recursivo(nodo->derecha, dano_enemigo);
		dano_enemigo += nodo->carta.get_Dano();
	}
}


int ArbolBinario::Calcular_costo() const
{
	int costo_total = 0;
	Calcular_costo_recursivo(raiz, costo_total);
	return costo_total;

}

void ArbolBinario::Calcular_costo_recursivo(NodoArbol* nodo, int& costo_total) const {
	if (nodo != nullptr) {
		Calcular_costo_recursivo(nodo->derecha, costo_total);
		costo_total += nodo->carta.get_Coste();

	}
}


void ArbolBinario::limpiarArbol(NodoArbol* nodo) {
	if (nodo != nullptr) {

		limpiarArbol(nodo->izquierda);
		limpiarArbol(nodo->derecha);

		delete nodo;
	}
}

void ArbolBinario::limpiarArbol() {
	limpiarArbol(raiz);
	raiz = nullptr;
}