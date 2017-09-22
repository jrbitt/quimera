#pragma once
#include "../Quimera/Quimera.h"

class Veiculo :
	public AgenteMovel
{
private:
	Vetor2D *destino;

public:
	Veiculo();
	~Veiculo();

	void setDestino(double a, double b);

	void inicializar(Ambiente *a = NULL);

};

