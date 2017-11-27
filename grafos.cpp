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
	std::vector<Deputy> Organize;
	for(int j=0;j<8;j++){
		forest.PathLengthLonger(j);
		Organize = forest.PathAnomally();

		for(int i=0;i<(signed)Organize.size();i++){
			if(std::find(Names.begin(),Names.end(),Organize[i].deputy_name) == Names.end()){
				Names.push_back(Organize[i].deputy_name);
			}

			if(std::find(States.begin(),States.end(),Organize[i].estate) == States.end()){
				States.push_back(Organize[i].estate);
			}

			if(std::find(Party.begin(),Party.end(),Organize[i].party) == Party.end()){
				Party.push_back(Organize[i].party);
			}

			if(std::find(Refound_Descriptions.begin(),Refound_Descriptions.end(),Organize[i].refound_description) == Refound_Descriptions.end()){
				Refound_Descriptions.push_back(Organize[i].refound_description);
			}

			if(std::find(Company_names.begin(),Company_names.end(),Organize[i].company_name) == Company_names.end()){
				Company_names.push_back(Organize[i].company_name);
			}

			if(std::find(Company_ids.begin(),Company_ids.end(),Organize[i].company_id) == Company_ids.end()){
				if(Organize[i].company_id < 0){
					Organize[i].company_id = Organize[i].company_id*(-1);
				}
				if(Organize[i].company_id !=0){
					Company_ids.push_back(Organize[i].company_id);
				}
			}

			if(std::find(Refound_Dates.begin(),Refound_Dates.end(),Organize[i].refund_date) == Refound_Dates.end()){
				Refound_Dates.push_back(Organize[i].refund_date);
			}

			if(std::find(Refound_Values.begin(),Refound_Values.end(),Organize[i].refund_value) == Refound_Values.end()){
				if(Organize[i].refund_value < 0){
					Organize[i].refund_value = Organize[i].refund_value*(-1);
				}
				if(Organize[i].refund_value != 0 ){
					Refound_Values.push_back(Organize[i].refund_value);
				}
			}
		}
	}
}

void Grafo::Sort_Vectors(){
	std::sort(Names.begin(),Names.end());
	std::sort(States.begin(),States.end());
	std::sort(Party.begin(),Party.end());
	std::sort(Refound_Descriptions.begin(),Refound_Descriptions.end());
	std::sort(Company_names.begin(),Company_names.end());
	std::sort(Company_ids.begin(),Company_ids.end());
	std::sort(Refound_Dates.begin(),Refound_Dates.end());
	std::sort(Refound_Values.begin(),Refound_Values.end());
	std::reverse(Refound_Values.begin(),Refound_Values.end());
}

void Grafo::CalculateForest(int limit_trees,int limite){
	if((limite!=0)&&(limite < 10000)){
		forest.iForest(lista_v,limit_trees,limite);
	}else{
		forest.iForest(lista_v,limit_trees);
	}
	find_anomally();
}

void Grafo::ImprimirDadosAnomalos(){
	Sort_Vectors();
	cout << "Nomes dos deputados" << endl;
	for(int i=0;i<(signed)Names.size();i++){
		cout << Names[i] << endl;
	}

	cout << endl << endl;

	cout << "Estados" << endl;
	for(int i=0;i<(signed)States.size();i++){
		cout << States[i] << endl;
	}

	cout << endl << endl;

	cout << "Partidos" << endl;
	for(int i=0;i<(signed)Party.size();i++){
		cout << Party[i] << endl;
	}
	cout << endl << endl;

	cout << "Descrição de reembolsos" << endl;
	for(int i=0;i<(signed)Refound_Descriptions.size();i++){
		cout << Refound_Descriptions[i] << endl;
	}
	cout << endl << endl;

	cout << "Nomes das Companias" << endl;
	for(int i=0;i<(signed)Company_names.size();i++){
		cout << Company_names[i] << endl;
	}
	cout << endl << endl;

	cout << "Identidade das Companias" << endl;
	for(int i=0;i<(signed)Company_ids.size();i++){
		cout << Company_ids[i] << endl;
	}
	cout << endl << endl;

	cout << "data do reembolso" << endl;
	for(int i=0;i<(signed)Refound_Dates.size();i++){
		cout << Refound_Dates[i] << endl;
	}
	cout << endl << endl;

	cout << "valores do reembolso" << endl;
	for(int i=0;i<(signed)Refound_Values.size();i++){
		cout << Refound_Values[i] << endl;
	}
	cout << endl << endl;
}

void Grafo::ImprimirGrafo()
{
	cout << "*** ANOMALIAS ENCONTRADAS ***" << endl;
	ImprimirDadosAnomalos();
	cout << "\n" << endl;
}