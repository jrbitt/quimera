#include "Transicao.h"



Transicao::Transicao()
{
	alvo = NULL;
	condicao = NULL;
	lstAcoes = new list<Acao*>;
}


Transicao::~Transicao()
{
}

bool Transicao::disparar()
{
	return condicao->testar();
}

Estado * Transicao::getEstadoAlvo()
{
	return alvo;
}

list<Acao*>* Transicao::getAcoes()
{
	return lstAcoes;
}

void Transicao::setEstadoAlvo(Estado * alvo)
{
	this->alvo = alvo;
}

void Transicao::setCondicao(Condicao * c)
{
	condicao = c;
}

void Transicao::addAcao(Acao * a)
{
	lstAcoes->push_back(a);
}

void Transicao::setNivel(int n)
{
	nivel = n;
}

int Transicao::getNivel()
{
	return nivel;
}
