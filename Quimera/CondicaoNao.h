#pragma once
#include "Condicao.h"
class CondicaoNao : public Condicao
{
private:
	Condicao *condA;
	
public:
	CondicaoNao(Condicao *a);
	~CondicaoNao();

	bool testar();
};

