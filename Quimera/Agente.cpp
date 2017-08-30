#include "Agente.h"



Agente::Agente()
{
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
