#pragma once
#include "Acao.h"
#include "Transicao.h"

#include <list>
using namespace std;

class Resultado {
public:
	list<Acao*>* acoes;
	Transicao *transicao;
	int nivel;

	Resultado() {
		acoes = new list<Acao*>;
		transicao = NULL;
		nivel = 0;
	}
};
class HierarquiaBase
{
public:
	HierarquiaBase();
	~HierarquiaBase();

	virtual list<Acao*>* getAcoes() = 0;
	virtual list<Estado*>* getEstados() = 0;

	Resultado atualizar();
};

