#include "grafos.hpp"


Grafo::Grafo()
{

}

Grafo::~Grafo()
{

}

void Grafo::InsereVertice(Deputy deputado)
{
	lista_v.push_back(deputado);
}

string Grafo::anomally_found(){
	return NULL;
}

void Grafo::ImprimirGrafo()
{
	//int i=0,j=0;
/*
	for(i=0;i<(signed)lista_v.size();i++){
		cout << "Deputado:" << lista_v[i].deputado << "\n";
		for(j=0;j < (signed)lista_v[i].listaAdjArest.size();j++){
			cout << "professores contratados:" << lista_v[i].listaAdjArest[j].ProfessorValor.nome << ",";
		}
		cout << "\n" << endl;
	}*/
}