#include "Estado.h"



Estado::Estado()
{
	lstAgir = NULL;
	lstEntrar = NULL;
	lstSair = NULL;
	lstTransicoes = NULL;
}


Estado::~Estado()
{
}

void Estado::addAcao(Acao * a, EstadoMomento em)
{
	switch (em)
	{
	case AO_ENTRAR: lstEntrar->push_back(a);
		break;
	case AO_EXECUTAR: lstAgir->push_back(a);
		break;
	case AO_SAIR: lstSair->push_back(a);
		break;
	}
}

void Estado::addTransicao(Transicao * t)
{
	lstTransicoes->push_back(t);
}

list<Acao*>* Estado::getAcoes()
{
	return lstAgir;
}

list<Acao*>* Estado::getAcoesAoEntrar()
{
	return lstEntrar;
}

list<Acao*>* Estado::getAcoesAoSair()
{
	return lstSair;
}

list<Transicao*>* Estado::getTransicoes()
{
	return lstTransicoes;
}
