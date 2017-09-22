#include "GerenteDeSteering.h"



GerenteDeSteering::GerenteDeSteering(AgenteMovel *a)
{
	dono = a;
}


GerenteDeSteering::~GerenteDeSteering()
{
}

Vetor2D GerenteDeSteering::calcular()
{
	Vetor2D ret;
	list<SteeringEntrada*>::iterator it;
	for (it = steerings.begin(); it != steerings.end(); it++) {
		ret += (*it)->steering->calcular()*(*it)->peso;
	}
	return ret;
}

void GerenteDeSteering::addSteering(Steering * s, double v)
{
	s->setDono(dono);
	SteeringEntrada *se;
	se->steering = s;
	se->peso = v;
	steerings.push_back(se);
}
