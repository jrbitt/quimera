#pragma once
#include "Estado.h"
#include "MaquinaDeEstadosHierarquica.h"

class EstadoSubMaquina :
	public Estado, public MaquinaDeEstadosHierarquica
{
public:
	EstadoSubMaquina();
	~EstadoSubMaquina();

	list<Acao*>* getAcoes();
	list<Acao*>* atualizar(Ambiente *a);
	list<Estado*>* getEstados();
};

