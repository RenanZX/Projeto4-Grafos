#include "grafos.hpp"

const int Grafo::DEP_NAME = 0;
const int Grafo::ESTATE = 1;
const int Grafo::PARTY = 2;
const int Grafo::REFOUND_DESCRIPTION = 3;
const int Grafo::COMPANY_NAME = 4;
const int Grafo::COMPANY_ID = 5;
const int Grafo::REFUND_DATE = 6;
const int Grafo::REFUND_VALUE = 7;


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

void Grafo::find_anomally(){
	int maior = 0;
	int corrente = 0;

	for(int i=0;i<8;i++){
		corrente = forest.PathLengthLonger(i);
		if(corrente >= maior){
			if((anomalies.size()!=0)&&(maior!=corrente)){
				anomalies.pop_back();
			}
			maior = corrente;
			anomalies.push_back(i);
		}
	}
}

void Grafo::CalculateForest(){
	forest.iForest(lista_v,100);
}

void Grafo::ImprimirGrafo()
{
	int i=0;

	cout << "*** ANOMALIAS ENCONTRADAS ***" << endl;
	for(i=0;i<(signed)anomalies.size();i++){
		switch(i){
			case DEP_NAME:
				cout << "Nomes dos deputados" << endl;
				break;
			case ESTATE:
				cout << "Estados" << endl;
				break;
			case PARTY:
				cout << "Partidos" << endl;
				break;
			case REFOUND_DESCRIPTION:
				cout << "Descrição de reembolsos" << endl;
				break;
			case COMPANY_NAME:
				cout << "Nomes das Companias" << endl;
				break;
			case COMPANY_ID:
				cout << "Identidade das Companias" << endl;
				break;
			case REFUND_DATE:
				cout << "data do reembolso" << endl;
				break;
			case REFUND_VALUE:
				cout << "valores do reembolso" << endl;
				break;
		}
		cout << "\n" << endl;
	}
}