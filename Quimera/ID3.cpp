#include "ID3.h"

/*

ID3::ID3()
{
	arvore = new Nodo<NodoID3*>();
}


ID3::~ID3()
{
}

void ID3::criarArvore(BaseDeExemplos *examples)
{
	//Define um vetor de atributos
	int tam = examples->getNumEntradas();
	int* attrs = new int[tam];
	for (int i = 0; i<tam; i++) {
		attrs[i] = i;
	}
	//Cria a arvore passando exemplos, lista de atributos e o nodo raiz
	criarArvore(examples, attrs, arvore);
}

Nodo<NodoID3*>* ID3::getArvore()
{
	return arvore;
}


void ID3::criarArvore(BaseDeExemplos *examples, int * attrs, Nodo<NodoID3*> *node)
{
	//Calcula a entropia inicial do conjunto de dados
	float initialEntropy = entropia(examples);
	//Se for menor ou igual a zero
	if (initialEntropy <= 0.0) {
		//Cria um nodo ID3
		NodoID3 *in = new NodoID3();
		in->atributoId = -1;
		in->conjuntos = NULL;
		in->base = examples;

		//Define no nodo com uma base de exemplos padrao. Nodo folha
		node.setValue(in);
		return;
	}
	else {
		//Pega o numero de exemplos
		int exampleCount = examples.getSize();

		//Armazena o melhor atributo
		float bestInformationGain = 0;
		HashMap<String, ArrayList<Example>> bestSets = null;
		int bestSplitAttribute = -1;

		//Caso não tenha atributo para dividir retorna
		if (attrs == null) return;

		//para cada atributo
		for (int i = 0; i<attrs.length; i++) {
			//divide a base por um determinado atributo
			HashMap<String, ArrayList<Example>> sets = splitByAttribute(examples, attrs[i]);
			//Calcula a entropia para os conjuntos
			float overallEntropy = entropyOfSets(sets, exampleCount);
			//Verifica o ganho da informação
			float informationGain = initialEntropy + overallEntropy;
			//Armazena aquela com maior ganho
			if (informationGain>bestInformationGain) {
				bestInformationGain = informationGain;
				bestSplitAttribute = attrs[i];
				bestSets = sets;
			}
		}

		//Cria um nodo ID3
		ID3Node in = new ID3Node();
		//Guarda o atributo divisor e o melhor conjunto
		in.value = bestSplitAttribute;
		in.sets = bestSets;
		node.setValue(in);

		//Define os novos atributos
		int[] newAttr = getAttrs(attrs, bestSplitAttribute);

		//Pega os valores do atributo
		Set<String> keys = bestSets.keySet();
		Iterator<String> it = keys.iterator();
		//Para cada valor
		while (it.hasNext()) {
			String k = it.next();
			//Pega a coleção de exemplos
			ArrayList<Example> set = bestSets.get(k);
			String attrValue = set.get(0).getValue(bestSplitAttribute);

			//Cria um nodo filho
			Node<ID3Node> daugther = new Node<ID3Node>();
			node.add(daugther, attrValue);

			//RECURSAO! nova base, considerando o novo atributo
			createTree(new ExamplesSet(set), newAttr, daugther);
		}
	}
	
}

//remove um atributo da lista de atributos
int * ID3::getAtributos(int * or, int length, int exc)
{
	int* attrs;
	if (exc == -1) {
		attrs = new int[length];
	}
	else {
		attrs = new int[length - 1];
	}
	if (length == 0) return NULL;
	int count = 0;
	for (int i = 0; i< length; i++) {
		if (or [i] != exc) {
			attrs[count++] = or [i];
		}
	}
	return attrs;
}

float ID3::entropiaDosConjuntos(map<string, list<Exemplo*>>* sets, int exampleCount)
{
	float e = 0;

	Set<String> keys = sets.keySet();
	Iterator<String> it = keys.iterator();
	while (it.hasNext()) {
		String k = it.next();
		ArrayList<Example> set = sets.get(k);

		float prop = (float)set.size() / (float)exampleCount;
		e -= prop*entropy(new ExamplesSet(set));
	}
	return e;
}

map<string, list<Exemplo*>>* ID3::dividirPorAtributo(BaseDeExemplos * examples, int attr)
{
	map<string, list<Exemplo*>>* sets = new map<string, list<Exemplo*>>();
	for (int i = 0; i<examples->getTamanho(); i++) {
		Exemplo *example = examples->getExemplo(i);
		string value = example->getValor(attr);
		if (sets->containsKey(value)) {
			sets.get(value).add(example);
		}
		else {
			list<Exemplo*> *lst = new list<Exemplo*>();
			lst->push_back(example);
			sets.put(value, lst);
		}
	}
	return sets;
}

float ID3::entropia(BaseDeExemplos * examples)
{
	//Pega o total de exemplos na base
	int exampleCount = examples->getTamanho();
	//Se não tem nada a entropia é zero
	if (exampleCount == 0) {
		return 0;
	}
	//se tem exemplos
	else {
		//Cria uma hash para ações. 
		map<string, int> *actions = new map<string,int>();
		//Conta quantos exemplos existem para uma ação
		contaAcoes(actions, examples);

		//Se não tem ações retorna zero
		if (actions->size() == 0) {
			return 0;
		}
		else {
			float entropy = 0.0f;
			//pegue todas as ações
			Set<String> keys = actions.keySet();
			//pega um iterador para as ações
			Iterator<String> it = keys.iterator();
			//enquanto tiver ações
			while (it.hasNext()) {
				//pega a ação
				String k = it.next();
				//pega a quantidade usando a ação
				int v = actions.get(k);
				//calcula proporção
				float prop = (float)v / (float)exampleCount;
				entropy -= prop*log(prop);
			}
			return entropy;
		}
	}
}

float ID3::log(float prop)
{
	return(float)(log(prop) / log(2.0));
}

void ID3::contaAcoes(map<string, int>* actions, BaseDeExemplos *examples)
{
	//Para cada exemplo
	for (int i = 0; i<examples->getTamanho(); i++) {
		//Pega o exemplo i
		Exemplo *example = examples->getExemplo(i);
		//Se as ações contem a ação do exemplo
		if (actions->containsKey(example->getSaida(0))) {
			//Pega o total dessa ação
			int cur = actions->get(example->getSaida(0));
			//Incrementa
			cur++;
			//Redefine com o novo valor
			actions.put(example->getSaida(0), cur);
		}
		else {
			//Se não possui guarda esta ação como uma ocorrencia
			actions.put(example->getSaida(0), 1);
		}
	}
}

NodoID3::NodoID3()
{
}
*/