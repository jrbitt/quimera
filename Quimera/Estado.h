#pragma once
#include "Acao.h"
#include "Transicao.h"
#include <list>
using namespace std;

class Transicao;

enum EstadoMomento {
	AO_ENTRAR,
	AO_EXECUTAR,
	AO_SAIR
};

class Estado
{
private:
	list<Acao*> *lstAgir;
	list<Acao*> *lstEntrar;
	list<Acao*> *lstSair;
	list<Transicao*> *lstTransicoes;

public:
	Estado();
	~Estado();

	void addAcao(Acao *a, EstadoMomento em);
	void addTransicao(Transicao *t);

	list<Acao*>* getAcoes();
	list<Acao*>* getAcoesAoEntrar();
	list<Acao*>* getAcoesAoSair();

	list<Transicao*>* getTransicoes();
};

