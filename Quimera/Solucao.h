#pragma once
#include <list>
#include "Comando.h"

using namespace std;

class Solucao
{
private:
	list<Comando*> comandos;
public:
	Solucao();
	~Solucao();

	void addPasso(Comando *op);
	list<Comando*>::iterator elementos();
	void remover(Comando* o);
	void remover();
};