#include "Nodo.h"



Nodo::Nodo()
{
	indice = -1;
}

Nodo::Nodo(int i)
{
	indice = i;
}


Nodo::~Nodo()
{
}

int Nodo::getIndice()
{
	return indice;
}

void Nodo::setIndice(int i)
{
	indice = i;
}
