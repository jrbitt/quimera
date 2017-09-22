#include "stdafx.h"
#include "Veiculo.h"


Veiculo::Veiculo(): AgenteMovel(Vetor2D(0,0),5.0,Vetor2D(0,0),15,Vetor2D(1,0),100,Vetor2D(1,1),0,100)
{
}


Veiculo::~Veiculo()
{
}

void Veiculo::setDestino(double a, double b)
{
	destino = new Vetor2D(a, b);
}

void Veiculo::inicializar(Ambiente * a)
{
	GerenteDeSteering *gerente = new GerenteDeSteering(this);
	Seek *seek = new Seek(destino);
	gerente->addSteering(seek);

	this->setGerenteDeSteering(gerente);

}
