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

void Grafo::find_anomally(){
	int maior = 0;
	int corrente = 0;

	for(int i=0;i<8;i++){
		corrente = forest.PathLengthLonger(i);
		if(corrente >= maior){
			if((anomalies.size()!=0)&&(maior!=corrente)){
				anomalies.pop_back();
				AnomaliePaths.pop_back();
			}
			maior = corrente;
			anomalies.push_back(i);
			AnomaliePaths.push_back(forest.PathAnomally());
		}
	}
}

void Grafo::CalculateForest(int limite){
	if((limite!=0)&&(limite < 10000)){
		forest.iForest(lista_v,100,limite);
	}else{
		forest.iForest(lista_v,100);
	}
	find_anomally();
}

void Grafo::ImprimirInstanciaAnomala(int x){
	switch(x){
		case DEP_NAME:
			for(int j=0;j<(signed)AnomaliePaths.size();j++){
				for(int i=0;i<(signed)AnomaliePaths[j].size();i++){
					cout << AnomaliePaths[j][i].deputy_name << endl;
				}
			}
			break;
		case ESTATE:
			for(int j=0;j<(signed)AnomaliePaths.size();j++){
				for(int i=0;i<(signed)AnomaliePaths[j].size();i++){
					cout << AnomaliePaths[j][i].estate << endl;
				}
			}
			break;
		case PARTY:
			for(int j=0;j<(signed)AnomaliePaths.size();j++){
				for(int i=0;i<(signed)AnomaliePaths[j].size();i++){
					cout << AnomaliePaths[j][i].party << endl;
				}
			}
			break;
		case REFOUND_DESCRIPTION:
			for(int j=0;j<(signed)AnomaliePaths.size();j++){
				for(int i=0;i<(signed)AnomaliePaths[j].size();i++){
					cout << AnomaliePaths[j][i].refound_description << endl;
				}
			}
			break;
		case COMPANY_NAME:
			for(int j=0;j<(signed)AnomaliePaths.size();j++){
				for(int i=0;i<(signed)AnomaliePaths[j].size();i++){
					cout << AnomaliePaths[j][i].company_name << endl;
				}
			}
			break;
		case COMPANY_ID:
			for(int j=0;j<(signed)AnomaliePaths.size();j++){
				for(int i=0;i<(signed)AnomaliePaths[j].size();i++){
					cout << AnomaliePaths[j][i].company_id << endl;
				}
			}
			break;
		case REFUND_DATE:
			for(int j=0;j<(signed)AnomaliePaths.size();j++){
				for(int i=0;i<(signed)AnomaliePaths[j].size();i++){
					cout << AnomaliePaths[j][i].refund_date << endl;
				}
			}
			break;
		case REFUND_VALUE:
			for(int j=0;j<(signed)AnomaliePaths.size();j++){
				for(int i=0;i<(signed)AnomaliePaths[j].size();i++){
					cout << AnomaliePaths[j][i].refund_value << endl;
				}
			}
			break;
	}
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
		ImprimirInstanciaAnomala(i);
		cout << "\n" << endl;
	}
}