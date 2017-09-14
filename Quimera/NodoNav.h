#pragma once
#include "Nodo.h"

template<class Tipo =void*>
class NodoNav: public Nodo {
protected:
	int x;
	int y;

	Tipo extra;

public:

	void setPos(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void setExtra(Tipo t) {
		extra = t;
	}

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	Tipo getExtra() {
		return extra;
	}
};