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

	ql.setAlpha(0.2f);
	ql.setGamma(0.8f);
	ql.setIteracoes(1000);
	ql.setNu(0.8f);
	ql.setRho(0.1f);

	ql.aprender();

	ql.salvar("lab.txt");
	
	int pos = 0;
	lab.setPosicoes(pos, 8);
	while (pos != 8) {
 		int acao = ql.agir(lab.getAtual());
		lab.mover((Direcoes)acao);
		pos = lab.getAtual();
		cout << "mover para " << pos << endl;
	}
    return 0;
}

