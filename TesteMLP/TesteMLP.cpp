// TesteMLP.cpp: Define o ponto de entrada para a aplicação de console.
//

#include "stdafx.h"
#include "../Quimera/MLP.h"
#include <iostream>
using namespace std;

int main()
{
	MLP redeNeural(2,2,1);
	redeNeural.setTaxaAprendizagem(0.2);

	float entrada[4][2] = { 
		{0.0f,0.0f},
		{0.0f,1.0f},
		{1.0f,0.0f},
		{1.0f,1.0f} };
	float saida[4][1] = {
		{0.0},
		{1.0},
		{1.0},
		{0.0} };

	
	for(int i=0; i<10000; i++) {
		float erro = 0;
		for (int i = 0; i < 4; i++) {
			erro += redeNeural.aprenderPadrao(entrada[i], saida[i]);
		}
		cout << "erro medio: " << erro / 4 << endl;
	}
    return 0;
}

