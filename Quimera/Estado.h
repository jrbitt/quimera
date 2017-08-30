#pragma once
#include "Acao.h"
#include "Transicao.h"
#include "HierarquiaBase.h"
#include <list>
using namespace std;

class Transicao;

enum EstadoMomento {
	AO_ENTRAR,
	AO_EXECUTAR,
	AO_SAIR
};

class Estado: public HierarquiaBase
{
private:
	list<Acao*> *lstAgir;
	list<Acao*> *lstEntrar;
	list<Acao*> *lstSair;
	list<Transicao*> *lstTransicoes;

	list<Estado*>* lstEstados;

public:
	Estado();
	~Estado();

	void addAcao(Acao *a, EstadoMomento em);
	void addTransicao(Transicao *t);

	list<Acao*>* getAcoes();
	list<Acao*>* getAcoesAoEntrar();
	list<Acao*>* getAcoesAoSair();

	list<Transicao*>* getTransicoes();

	list<Estado*>* getEstados();
};

