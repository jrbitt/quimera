#include "MaquinaDeEstadosHierarquica.h"

MaquinaDeEstadosHierarquica::MaquinaDeEstadosHierarquica()
{
	atual = inicial = NULL;
}


MaquinaDeEstadosHierarquica::~MaquinaDeEstadosHierarquica()
{
}

void MaquinaDeEstadosHierarquica::setEstadoInicial(Estado * e)
{
	atual = inicial = e;
}


list<Estado*>* MaquinaDeEstadosHierarquica::getEstados()
{
	if (atual != NULL) {
		return atual->getEstados();
	}
	else {
		list<Estado*>* temp = new list<Estado*>;
		return temp;
	}
}

list<Acao*>* MaquinaDeEstadosHierarquica::atualizar()
{
	if (!atual) {
		atual = inicial;
		return atual->getAcoesAoEntrar();
	}

	Transicao *disparada = NULL;
	list<Transicao*>* transicoes = atual->getTransicoes();
	list<Transicao*>::iterator it;
	for (it = transicoes->begin(); it != transicoes->end(); it++) {
		if ((*it)->disparar()) {
			disparada = *it;
			break;
		}
	}

	Resultado *r = NULL;
	if (disparada != NULL) {
		r = new Resultado;
		r->transicao = disparada;
		r->nivel = disparada->getNivel();
	}
	else {
		r = atual->
	}
}