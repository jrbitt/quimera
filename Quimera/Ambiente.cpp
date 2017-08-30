#include "Ambiente.h"


Ambiente* Ambiente::instancia = NULL;

Ambiente& Ambiente::getInstancia()
{
	if (instancia == NULL) {
		instancia = new Ambiente;
	}
	return *instancia;
}

bool & Ambiente::operator[](string b)
{
	return mapaBool[b];
}

Ambiente::Ambiente()
{
}


Ambiente::~Ambiente()
{
}

