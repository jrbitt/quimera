// TesteSteering.cpp: Define o ponto de entrada para a aplicação de console.
//

#include "stdafx.h"
#include "Veiculo.h"

int main()
{
	Veiculo carro;

	carro.setPosicao(Vetor2D(0, 0));
	carro.setDestino(50, 50);

	for (int i = 0; i < 100; i++) {
		carro.atualizar(1);
	}
	
    return 0;
}

