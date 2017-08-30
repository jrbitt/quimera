#include "CondicaoOu.h"



CondicaoOu::CondicaoOu(Condicao *a, Condicao *b)
{
	condA = a;
	condB = b;
}


CondicaoOu::~CondicaoOu()
{
}

bool CondicaoOu::testar()
{
	return condA->testar() || condB->testar();
}
