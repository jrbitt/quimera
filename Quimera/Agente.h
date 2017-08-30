#pragma once
#include "Acao.h"
#include "Ambiente.h"
#include "Controle.h"
#include <list>
using namespace std;

class Agente
{
protected:
	Controle* controle;

public:
	Agente();
	~Agente();

	void setControle(Controle *c);
	list<Acao*>* agir(Ambiente *a);

	virtual void inicializar(Ambiente *a=NULL) = 0;
};

