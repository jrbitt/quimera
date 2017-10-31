// TesteAR.cpp: Define o ponto de entrada para a aplicação de console.
//

#include "stdafx.h"
#include "Labirinto.h"
#include "../Quimera/QLearning.h"
#include <iostream>

using namespace std;

int main()
{
	Labirinto lab(8);
	QLearning ql(&lab);

	ql.setAlpha(0.4f);
	ql.setGamma(0.75f);
	ql.setIteracoes(100);
	ql.setNu(0.0f);
	ql.setRho(0.2f);

	ql.aprender();

	
	int pos = 0;
	lab.setPosicoes(pos, 8);
	while (pos != 8) {
		int acao = ql.agir(lab.getAtual());
		lab.mover((Direcoes)acao);
		pos = lab.getAtual();
		cout << "mover para " << acao << endl;
	}
    return 0;
}

