#include "Aresta.h"



Aresta::Aresta(int de, int para, float c)
{
	origem = de;
	destino = para;
	custo = c;
}

Aresta::Aresta(int de, int para)
{
	origem = de;
	destino = para;
	custo = 1.0f;
}

Aresta::Aresta()
{
	origem = -1;
	destino = -1;
	custo = -1.0f;
}


Aresta::~Aresta()
{
}

void Aresta::setOrigem(int de)
{
	origem = de;
}

void Aresta::setDestino(int para)
{
	destino = para;
}

void Aresta::setCusto(float c)
{
	custo = c;
}

int Aresta::getOrigem()
{
	return origem;
}

int Aresta::getDestino()
{
	return destino;
}

float Aresta::getCusto()
{
	return custo;
}
