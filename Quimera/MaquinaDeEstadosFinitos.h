#pragma once
#include <list>
#include "Estado.h"]
#include "Controle.h"

using namespace std;

class MaquinaDeEstadosFinitos: public Controle
{
private:
	list<Estado*> *lstEstados;
	Estado* inicial;
	Estado* atual;

public:
	MaquinaDeEstadosFinitos();
	~MaquinaDeEstadosFinitos();

	void addEstado(Estado *e);
	void setEstadoInicial(Estado *e);
	list<Acao*>* atualizar(Ambiente *e);
};

