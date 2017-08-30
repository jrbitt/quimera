#pragma once
#include <list>
#include "Acao.h"
#include "Ambiente.h"

using namespace std;

class Controle {
public:
	virtual list<Acao*>* atualizar(Ambiente *a) = 0;
};