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


list<HierarquiaBase*>* MaquinaDeEstadosHierarquica::getEstados()
{
	if (atual != NULL) {
		return atual->getEstados();
	}
	else {
		list<HierarquiaBase*>* temp = new list<HierarquiaBase*>;
		return temp;
	}
}

list<Acao*>* MaquinaDeEstadosHierarquica::atualizarPraBaixo(HierarquiaBase * e, int nivel)
{
	list<Acao*>* acoes = new list<Acao*>;
	if (nivel > 0) {
		acoes = estadoPai->atualizarPraBaixo(this, nivel - 1);
	}

	if (atual != NULL) {
		(*acoes)+=atual->getAcoesAoSair();
	}
	atual =(Estado*) e;
	(*acoes) += atual->getAcoesAoEntrar();
	return acoes;
}



list<Acao*>* MaquinaDeEstadosHierarquica::atualizar(Ambiente *a)
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
		r = atual->atualizar();
	}

	if (r->transicao != NULL) {
		if (r->nivel == 0) {
			Estado *alvo = r->transicao->getEstadoAlvo();
			*(r->acoes) += atual->getAcoesAoSair();
			*(r->acoes) += r->transicao->getAcoes();
			*(r->acoes) += alvo->getAcoesAoEntrar();
			*(r->acoes) += alvo->getAcoes();

			atual = alvo;
			*(r->acoes) += getAcoes();
			r->transicao = NULL;
		}
		else if (r->nivel > 0) {
			*(r->acoes) += atual->getAcoesAoSair();
			atual = NULL;
			r->nivel -= 1;
		}
		else {
			HierarquiaBase *alvo = r->transicao->getEstadoAlvo();
			HierarquiaBase *maquina = alvo->getEstadoPai();
			*(r->acoes) += r->transicao->getAcoes();
			*(r->acoes) += maquina->atualizarPraBaixo(alvo, --(r->nivel));
			r->transicao = NULL;
		}
	}
	else {
		*(r->acoes) += atual->getAcoes();
	}
	return r->acoes;
}