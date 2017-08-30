#include "Escrever.h"
#include "stdafx.h"


Escrever::Escrever(string m)
{
	msg = m;
}


Escrever::~Escrever()
{
}

void Escrever::fazer()
{
	cout << msg << endl;
}
