#include "Steering.h"



Steering::Steering()
{

}


Steering::~Steering()
{
}

void Steering::setDono(AgenteMovel * a)
{
	dono = a;
}

AgenteMovel* Steering::getDono()
{
	return dono;
}
