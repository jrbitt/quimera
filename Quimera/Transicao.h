#pragma once
#include "Condicao.h"
#include "Estado.h"
#include <list>
using namespace std;

class Estado;

class Transicao
{
private:
	Estado *alvo;
	list<Acao*> *lstAcoes;
	Condicao* condicao;
	int nivel;

public:
	Transicao();
	~Transicao();

	bool disparar();
	Estado* getEstadoAlvo();
	list<Acao*>* getAcoes();

	void setEstadoAlvo(Estado *alvo);
	void setCondicao(Condicao *c);
	void addAcao(Acao *a);

	void setNivel(int n);
	int getNivel();
};

