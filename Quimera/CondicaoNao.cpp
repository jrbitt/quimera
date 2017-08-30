#include "CondicaoNao.h"



CondicaoNao::CondicaoNao(Condicao *a)
{
	condA = a;
}


CondicaoNao::~CondicaoNao()
{
}

bool CondicaoNao::testar()
{
	return !condA->testar();
}
