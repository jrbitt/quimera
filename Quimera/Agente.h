#pragma once
#include "Acao.h"
#include "Ambiente.h"
#include "Controle.h"
#include <list>
using namespace std;

class Agente
{
private:
	int id;
	static int proximoId;

	void setId(int i);

protected:
	Controle* controle;

public:
	Agente(int i);
	~Agente();

	void setControle(Controle *c);
	list<Acao*>* agir(Ambiente *a);

	virtual void inicializar(Ambiente *a=NULL) = 0;

	int getId() const;
};

