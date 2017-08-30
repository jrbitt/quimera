#pragma once
#include "Condicao.h"
class CondicaoOu : public Condicao
{
private:
	Condicao *condA;
	Condicao *condB;
public:
	CondicaoOu(Condicao *a, Condicao *b);
	~CondicaoOu();

	bool testar();
};

