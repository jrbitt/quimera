#include "stdafx.h"
#include "Labirinto.h"
#include <iostream>
using namespace std;

Labirinto::Labirinto(int i, int f)
{
	inicio = i;
	fim = f;
}


Labirinto::~Labirinto()
{
}

int Labirinto::getEstadoRandomico()
{
	return inicio;
}

//0 3 2
//1 0 3 2
//2 0 3
//3 1 3 2
//4 0 1 3 2
//5 0 1 3
//6 1 2
//7 0 1 2
//8 0 1
vector<int>* Labirinto::getAcoes(int estado)
{
	vector<int>* v = new vector<int>;
	switch (estado) {
	case 0:
	{
		v->push_back(2);
		v->push_back(3);
	}
	case 1:
	{
		v->push_back(0);
		v->push_back(2);
		v->push_back(3);
	}
	case 2:
	{
		v->push_back(2);
		v->push_back(3);
	}
	case 3: 
	{
		v->push_back(1);
		v->push_back(2);
		v->push_back(3);
	}
	case 4:
	{
		v->push_back(0);
		v->push_back(1);
		v->push_back(2);
		v->push_back(3);
	}
	case 5: 
	{
		v->push_back(0);
		v->push_back(1);
		v->push_back(3);
	}
	case 6: 
	{
		v->push_back(1);
		v->push_back(2);
	}
	case 7:
	{
		v->push_back(0);
		v->push_back(1);
		v->push_back(2);
	}
	case 8:
	{
		v->push_back(0);
		v->push_back(1);
	}
	}
	return v;
}

ProblemaAprReforco::ParProblema Labirinto::tomarAcao(int estado, int acao)
{
	cout << "estou em " << estado << " fiz " << acao << endl;
	ProblemaAprReforco::ParProblema pp;
	switch (estado) {
	case 0:
		if (acao == 2) pp.novoEstado = 1;
		if (acao == 3) pp.novoEstado = 3;
		break;
	case 1:
		if (acao == 0) pp.novoEstado = 0;
		if (acao == 2) pp.novoEstado = 2;
		if (acao == 3) pp.novoEstado = 4;
		break;
	case 2:
		if (acao == 0) pp.novoEstado = 1;
		if (acao == 3) pp.novoEstado = 5;
		break;
	case 3:
		if (acao == 1) pp.novoEstado = 0;
		if (acao == 2) pp.novoEstado = 4;
		if (acao == 3) pp.novoEstado = 6;
		break;
	case 4:
		if (acao == 0) pp.novoEstado = 3;
		if (acao == 1) pp.novoEstado = 1;
		if (acao == 2) pp.novoEstado = 5;
		if (acao == 3) pp.novoEstado = 7;
		break;
	case 5:
		if (acao == 0) pp.novoEstado = 4;
		if (acao == 1) pp.novoEstado = 2;
		if (acao == 3) pp.novoEstado = 8;
		break;
	case 6:
		if (acao == 1) pp.novoEstado = 3;
		if (acao == 2) pp.novoEstado = 7;
		break;
	case 7:
		if (acao == 0) pp.novoEstado = 6;
		if (acao == 1) pp.novoEstado = 4;
		if (acao == 2) pp.novoEstado = 8;
		break;
	case 8:
		if (acao == 0) pp.novoEstado = 7;
		if (acao == 1) pp.novoEstado = 5;
		break;
	}
	cout << "...fui para " << pp.novoEstado << endl;
	if (pp.novoEstado == fim) {
		pp.recompensa = 1;
		terminou = true;
		cout << "cheguei" << endl;
	}
	else {
		pp.recompensa = -1;
	}
	return pp;
}

int Labirinto::getNumEstados()
{
	return 9;
}

int Labirinto::getNumMaxAcoes()
{
	return 4;
}

bool Labirinto::acabou()
{
	return terminou;
}
