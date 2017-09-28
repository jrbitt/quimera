#pragma once
template<class V>
class Atributo
{
private:
	string nome;
	V valor;
public:
	Atributo() {
		nome = "";
	}

	Atributo(string n, V v) {
		nome = n;
		valor = v;
	}
	~Atributo(){}

	void setNome(string n) {
		nome = n;
	}

	void setValor(V v) {
		valor = v;
	}

	string getNome() {
		return nome;
	}

	V getValor() {
		return valor;
	}
};

