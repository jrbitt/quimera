#pragma once
#include "Acao.h"
#include "Transicao.h"

#include <list>
using namespace std;

class Resultado {
public:
	list<Acao*>* acoes;
	Transicao* transicao;
	int nivel;

	Resultado() {
		acoes = new list<Acao*>;
		transicao = NULL;
		nivel = 0;
	}
};
class HierarquiaBase
{
protected:
	HierarquiaBase* estadoPai;

public:
	HierarquiaBase();
	~HierarquiaBase();

	virtual list<Acao*>* getAcoes() = 0;
	virtual list<HierarquiaBase*>* getEstados() = 0;
	virtual list<Acao*>* atualizarPraBaixo(HierarquiaBase *e, int nivel) { return NULL; }

	Resultado* atualizar();
	void setEstadoPai(HierarquiaBase* e);
	HierarquiaBase* getEstadoPai();
};

