#include "MaquinaDeEstadosFinitos.h"
#include "Transicao.h"

MaquinaDeEstadosFinitos::MaquinaDeEstadosFinitos()
{
	inicial = atual = NULL;
	lstEstados = new list<Estado*>;
}


MaquinaDeEstadosFinitos::~MaquinaDeEstadosFinitos()
{
}

void MaquinaDeEstadosFinitos::addEstado(Estado * e)
{
	lstEstados->push_back(e);
}

void MaquinaDeEstadosFinitos::setEstadoInicial(Estado * e)
{
	atual = inicial = e;
}

list<Acao*>* MaquinaDeEstadosFinitos::atualizar()
{
	Transicao *disparada = NULL;

	if(atual!=NULL){
		list<Transicao*>::iterator it = atual->getTransicoes()->begin();
		for (it; it!=atual->getTransicoes()->end(); it++) {
			if ((*it)->disparar()) {
				disparada = (*it);
				break;
			}
		}

		if (disparada != NULL) {
			Estado *alvo = disparada->getEstadoAlvo();
			list<Acao*> *saida = new list<Acao*>;
			list<Acao*>::iterator it;
			for (it = atual->getAcoesAoSair()->begin(); it != atual->getAcoesAoSair()->end(); it++) {
				saida->push_back((*it));
			}
			for (it = disparada->getAcoes()->begin(); it != disparada->getAcoes()->end(); it++) {
				saida->push_back((*it));
			}
			for (it = alvo->getAcoesAoEntrar()->begin(); it != alvo->getAcoesAoEntrar()->end(); it++) {
				saida->push_back((*it));
			}
			atual = alvo;
			return saida;
		}
		else {
			return atual->getAcoes();
		}
	}
	return NULL;
}
