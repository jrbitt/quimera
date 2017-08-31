#pragma once
#include "HierarquiaBase.h"
#include "Controle.h"
#include <list>
using namespace std;

class MaquinaDeEstadosHierarquica :
	public HierarquiaBase, public Controle
{
protected:
	list<HierarquiaBase*>* lstEstados;
	Estado* inicial;
	Estado* atual;

	list<Acao*>* atualizar(Ambiente *a);
	list<Acao*>* atualizarPraBaixo(HierarquiaBase *e, int nivel);


public:
	MaquinaDeEstadosHierarquica();
	~MaquinaDeEstadosHierarquica();

	void setEstadoInicial(Estado * e);

	list<HierarquiaBase*>* getEstados();
};

