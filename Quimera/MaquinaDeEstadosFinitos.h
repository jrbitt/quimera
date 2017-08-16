#pragma once
#include <list>
#include "Estado.h"

using namespace std;

class MaquinaDeEstadosFinitos
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
	list<Acao*>* atualizar();
};

