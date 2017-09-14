#include "CondicaoAmbiente.h"


CondicaoAmbiente::CondicaoAmbiente(string v)
{
	var = v;
}

CondicaoAmbiente::~CondicaoAmbiente()
{
}

bool CondicaoAmbiente::testar()
{
	return Ambiente::getInstancia().getBool(var);
}
