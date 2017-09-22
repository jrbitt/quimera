#pragma once
#include "Steering.h"
class Seek :
	public Steering
{
private:
	Vetor2D *alvo;

public:
	Seek(Vetor2D *a);
	~Seek();

	void setAlvo(Vetor2D *a);
	Vetor2D* getAlvo();

	Vetor2D calcular();
};

