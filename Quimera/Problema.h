#pragma once
#include <list>
#include "Nodo.h"

using namespace std;
template<class V>
class Problema{
protected:

	V estadoInicial;

public:
	V getEstadoInicial() {
		return estadoInicial;
	}

	void setEstadoInicial(V ei) {
		this.estadoInicial = ei;
	}

	virtual bool isMeta(V ref) = 0;
	virtual list<Nodo<V>> expandir(Nodo<V> nodo) = 0;
};