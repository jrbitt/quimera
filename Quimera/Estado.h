#pragma once
#include "Acao.h"
#include "Transicao.h"
//#include "HierarquiaBase.h"
#include <list>
using namespace std;

class HierarquiaBase;
class Transicao;

enum EstadoMomento {
	AO_ENTRAR,
	AO_EXECUTAR,
	AO_SAIR
};

class Estado //: public HierarquiaBase
{
private:
	list<Acao*> *lstAgir;
	list<Acao*> *lstEntrar;
	list<Acao*> *lstSair;
	list<Transicao*> *lstTransicoes;

protected:
	list<HierarquiaBase*>* lstEstados;

public:
	Estado();
	~Estado();

	void addAcao(Acao *a, EstadoMomento em);
	void addTransicao(Transicao *t);

	list<Acao*>* getAcoes();
	list<Acao*>* getAcoesAoEntrar();
	list<Acao*>* getAcoesAoSair();

	list<Transicao*>* getTransicoes();

	//list<HierarquiaBase*>* getEstados();


};

list<Estado*>& operator+=(list<Estado*>& a, list<Estado*>* b)
{
	list<Estado*>::iterator it;
	for (it = b->begin(); it != b->end(); it++) {
		a.push_back(*it);
	}
	return a;
}

list<HierarquiaBase*>& operator+=(list<HierarquiaBase*>& a, list<HierarquiaBase*>* b)
{
	list<HierarquiaBase*>::iterator it;
	for (it = b->begin(); it != b->end(); it++) {
		a.push_back(*it);
	}
	return a;
}

list<Acao*>& operator+=(list<Acao*>& a, list<Acao*>* b)
{
	list<Acao*>::iterator it;
	for (it = b->begin(); it != b->end(); it++) {
		a.push_back(*it);
	}
	return a;
}