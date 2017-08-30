#include "CondicaoE.h"



CondicaoE::CondicaoE(Condicao *a, Condicao *b)
{
	condA = a;
	condB = b;
}
//--

CondicaoE::~CondicaoE()
{
}

bool CondicaoE::testar()
{
	return condA->testar() && condB->testar();
}
