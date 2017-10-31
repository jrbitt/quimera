#pragma once
#include "../Quimera/ProblemaAprReforco.h"

//grid 3 x 3
// 0   1   2
// 3   4   5
// 6   7   8
//inicia em um canto e deve chegar no outro
//gera 9 estados posição do grid e 4 ações (cima,baixo,esquerda,direita)

enum Direcoes {
	ESQ, CIMA, DIR, BAIXO
};

class Labirinto: public ProblemaAprReforco
{
private:
	int inicio, fim;
	bool terminou;
	int atual;

public:
	Labirinto(int f);
	Labirinto();
	~Labirinto();

	void setPosicoes(int i, int f);
	int getEstadoRandomico();
	vector<int>* getAcoes(int estado);
	ProblemaAprReforco::ParProblema tomarAcao(int estado, int acao);

	int getNumEstados();
	int getNumMaxAcoes();

	bool acabou();

	int getAtual();
	void setAtual(int a);
	void mover(Direcoes d);
};

