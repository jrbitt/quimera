#include "Seek.h"



Seek::Seek(Vetor2D *a)
{
	alvo = a;
}


Seek::~Seek()
{
}

void Seek::setAlvo(Vetor2D * a)
{
	alvo = a;
}

Vetor2D * Seek::getAlvo()
{
	return alvo;
}

Vetor2D Seek::calcular()
{
	Vetor2D temp(*alvo - dono->getPosicao());
	temp.normalizar();
	Vetor2D velDesejada = temp * dono->getVelocidadeMax();
	return (velDesejada - dono->getVelocidade());
}
