#pragma once
#include "HierarquiaBase.h"
#include "Estado.h"
#include <list>
using namespace std;

class MaquinaDeEstadosHierarquica :
	public HierarquiaBase
{
private:
	list<Estado*>* lstEstados;
	Estado* inicial;
	Estado* atual;

protected:
	list<Acao*>* atualizar();

public:
	MaquinaDeEstadosHierarquica();
	~MaquinaDeEstadosHierarquica();

	void setEstadoInicial(Estado * e);

	list<Estado*>* getEstados();
};

