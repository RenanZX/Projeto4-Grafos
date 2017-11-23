#include "grafos.hpp"
#include "dados.hpp"

int main(){
  
  Grafo grafo;

  Deputy dep;
  dep.deputy_name = "sei la";
  dep.estate = "hedod";
  dep.party = "par";
  dep.refound_description = "asdasd";
  dep.company_name = "asdasd";
  dep.company_id = 123413;
  dep.refund_date = "20-10-2092";
  dep.refund_value = 23342;

  grafo.InsereVertice(dep);
  grafo.CalculateForest();
  grafo.ImprimirGrafo();

	return 0;
}
