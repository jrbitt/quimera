#pragma once
#include "Condicao.h"
class CondicaoE : public Condicao
{
private:
	Condicao *condA;
	Condicao *condB;
public:
	CondicaoE(Condicao *a, Condicao *b);
	~CondicaoE();

	bool testar();
};

