#pragma once
#include <map>
#include <string>
using namespace std;

class Ambiente
{
public:

	static Ambiente& getInstancia();
	
	bool& operator[](string b);

private:
	Ambiente();
	~Ambiente();

	map<string, bool> mapaBool;

	static Ambiente *instancia;
};

