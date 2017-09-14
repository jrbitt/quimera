#include "Agente.h"

int Agente::proximoId = 0;

Agente::Agente(int i)
{
	setId(i);
}


void Agente::setId(int i)
{
	if (i >= proximoId) {
		id = i;
		proximoId++;
	}
}

Agente::~Agente()
{
}

void Agente::setControle(Controle * c)
{
	controle = c;
}

list<Acao*>* Agente::agir(Ambiente * a)
{
	return controle->atualizar(a);
}

int Agente::getId() const
{
	return id;
}
