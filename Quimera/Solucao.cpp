#include "Solucao.h"



Solucao::Solucao()
{
}


Solucao::~Solucao()
{
}

void Solucao::addPasso(Comando * op)
{
	comandos.push_back(op);
}

list<Comando*>::iterator Solucao::elementos()
{
	return comandos.begin();
}

void Solucao::remover(Comando * o)
{
	comandos.remove(o);
}

void Solucao::remover()
{
	comandos.pop_back();
}