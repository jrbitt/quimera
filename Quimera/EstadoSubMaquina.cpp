#include "EstadoSubMaquina.h"

/*

EstadoSubMaquina::EstadoSubMaquina()
{
}


EstadoSubMaquina::~EstadoSubMaquina()
{
}

list<Acao*>* EstadoSubMaquina::getAcoes()
{
	return Estado::getAcoes();
}

list<HierarquiaBase*>* EstadoSubMaquina::getEstados()
{
	list<HierarquiaBase*>* temp = new list<HierarquiaBase*>;
	temp->push_back((Estado*)this);
	if (this->atual != NULL) {
		list<HierarquiaBase*>* e = atual->getEstados();
		(*temp) += e;
		return temp;
	}
	else {
		return temp;
	}
}

list<Acao*>* EstadoSubMaquina::atualizar(Ambiente *a)
{
	return MaquinaDeEstadosHierarquica::atualizar(a);
}
*/