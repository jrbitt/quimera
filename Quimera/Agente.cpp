#include "Agente.h"
#include <algorithm>

int Agente::proximoId = 0;

Agente::Agente(int i)
{
	setId(i);
}


void Agente::setId(int i)
{
	if (i >= proximoId) {
		id = i;
		proximoId++;
	}
}

Agente::~Agente()
{
}

void Agente::setControle(Controle * c)
{
	controle = c;
}

list<Acao*>* Agente::agir(Ambiente * a)
{
	return controle->atualizar(a);
}

int Agente::getId() const
{
	return id;
}

Vetor2D Agente::getPosicao() const
{
	return posicao;
}

void Agente::setPosicao(Vetor2D np)
{
	posicao = np;
}

double Agente::getRaio() const
{
	return raio;
}

void Agente::setRaio(double r)
{
	raio = r;
}

Vetor2D Agente::getEscala() const
{
	return escala;
}

void Agente::setEscala(Vetor2D val)
{
	raio *= max(val.getX(), val.getY()) / max(escala.getX(), escala.getY()); 
	escala = val;
}

void Agente::setEscala(double val)
{
	raio *= (val / max(escala.getX(), escala.getY())); 
	escala = Vetor2D(val, val);
}
