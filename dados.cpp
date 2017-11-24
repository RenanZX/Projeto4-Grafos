#include "dados.hpp"

<<<<<<< HEAD
void InsereRegistros(Grafo *grafo){
  Deputy dep;

  string line;
  string deputy_id, deputy_name,deputy_state,political_party,refund_description,company_name,company_id,refund_date,refund_value;

  int i=1;
  ifstream txtFile;
  txtFile.open("dados-com300-registros");
     

  // Passa pelas linhas que tem informacoes acerca dos professores
  while(!txtFile.eof()){

    getline(txtFile, line);// Pega a linha do loop.

    if (i == 1){ // teste para ele pular a primeira linha
      cout << "1st line ==> "+line << "\n" <<endl;
    } else {
      
      istringstream iss(line); // variavel para poder salvar os elementos.

      getline(getline(getline(getline(getline(getline(getline(getline(getline(iss, deputy_id, ','), deputy_name, ','), deputy_state, ','), political_party, ','), refund_description,','), company_name, ','), company_id, ','), refund_date, ','), refund_value, ',');
      
      // TESTE DEBUGGER
      cout << "| deputy_id: "           << deputy_id
           << "| deputy_name: "         << deputy_name
           << "| deputy_state: "        << deputy_state
           << "| political_party: "     << political_party
           << "| refund_description: "  << refund_description
           << "| company_name: "        << company_name
           << "| company_id: "          << company_id
           << "| refund_date: "         << refund_date
           << "| refund_value: "        << refund_value << "\n\n ### ANOTHER REGISTER: #" <<endl;

      dep.deputy_name = deputy_name;
      dep.estate = deputy_state;
      dep.party = political_party;
      dep.refound_description = refund_description;
      dep.company_name = company_name;
      dep.company_id = atoi(company_id.c_str());
      dep.refund_date = refund_date;
      dep.refund_value = atoi(refund_value.c_str());
      
      grafo->InsereVertice(dep);
    }    

    i++;    
  }
}
=======
>>>>>>> b5069c9873875f9ad6a451ab6200d420af24db39
