#include "HierarquiaBase.h"



HierarquiaBase::HierarquiaBase()
{
}


HierarquiaBase::~HierarquiaBase()
{
}

Resultado HierarquiaBase::atualizar()
{
	Resultado r;
	r.acoes = getAcoes();
	return r;
}
