#pragma once
#include "Vetor2D.h"
#include "Steering.h"

#include <list>
using namespace std;

class AgenteMovel;
class Steering;

class GerenteDeSteering
{
public:
	GerenteDeSteering(AgenteMovel *a);
	~GerenteDeSteering();

	Vetor2D calcular();

	void addSteering(Steering *s, double v = 1.0);

private:
	AgenteMovel *dono;


	class SteeringEntrada {
	public:
		Steering *steering;
		double peso;
	};

	list<SteeringEntrada*> steerings;
};

