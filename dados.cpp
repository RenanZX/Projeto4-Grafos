#include "dados.hpp"


void InsereRegistros(Grafo *grafo, int nro_reg){
  Deputy dep;

  string line;
  string deputy_id, deputy_name,deputy_state,political_party,refund_description,company_name,company_id,refund_date,refund_value;

  int i=1;
  ifstream txtFile;
  txtFile.open("dirty_deputies_v2-withoutAnyCols");
  

  // Passa pelas linhas que tem informacoes acerca dos politicos
  while(!txtFile.eof() && (i-1) <= nro_reg){ // OBS: esse 1000000 representa a quantidade que vc quer ler.

    getline(txtFile, line);// Pega a linha do loop.

    if (i == 1){ // teste para ele pular a primeira linha
      cout << "1st line ==> "+line << "\n" <<endl;
    } else {
      
      istringstream iss(line); // variavel para poder salvar os elementos.

      getline(getline(getline(getline(getline(getline(getline(getline(getline(iss, deputy_id, ','), deputy_name, ','), deputy_state, ','), political_party, ','), refund_description,','), company_name, ','), company_id, ','), refund_date, ','), refund_value, ',');
      
      // TESTE DEBUGGER
      cout << "###   Informações sobre o político lido:    ###\n"
           << "| deputy_id: "           << deputy_id
           << "| deputy_name: "         << deputy_name
           << "| deputy_state: "        << deputy_state
           << "| political_party: "     << political_party
           << "| refund_description: "  << refund_description
           << "| company_name: "        << company_name
           << "| company_id: "          << company_id
           << "| refund_date: "         << refund_date
           << "| refund_value: "        << refund_value << "\n" <<endl;

      dep.deputy_name = deputy_name;
      dep.estate = deputy_state;
      dep.party = political_party;
      dep.refound_description = refund_description;
      dep.company_name = company_name;
      dep.company_id = atof(company_id.c_str());
      //dep.company_id = company_id; versao salva como string
      dep.refund_date = refund_date;
      dep.refund_value = atof(refund_value.c_str());
      
      grafo->InsereVertice(dep);
    }    

    i++;    
  }
}
