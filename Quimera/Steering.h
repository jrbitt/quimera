#pragma once
#include "Vetor2D.h"
#include "AgenteMovel.h"

class AgenteMovel;

class Steering
{
protected:
	AgenteMovel *dono;

public:
	Steering();
	~Steering();

	void setDono(AgenteMovel *a);
	AgenteMovel* getDono();

	virtual Vetor2D calcular() = 0;
};

