#pragma once
#include "Condicao.h"
template<class Alias>
class EntreCondicao : public Condicao
{
private:
	Alias minValue, maxValue,valor;
public:
	EntreCondicao(Alias mn, Alias mx) {
		minValue = mn;
		maxValue = mx;
	}

	void setValor(Alias v) {
		valor = v;
	}

	bool testar() {
		return minValue <= valor <= maxValue;
	}
};

