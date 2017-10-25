// TesteAR.cpp: Define o ponto de entrada para a aplicação de console.
//

#include "stdafx.h"
#include "Labirinto.h"
#include "../Quimera/QLearning.h"

int main()
{
	Labirinto lab(0, 8);
	QLearning ql(&lab);

	ql.setAlpha(0.4f);
	ql.setGamma(0.75f);
	ql.setIteracoes(10000);
	ql.setNu(0.0f);
	ql.setRho(0.2f);

	ql.aprender();
    return 0;
}

