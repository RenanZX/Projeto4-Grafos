#include "grafos.hpp"
#include "dados.hpp"

int main(){
  
  Grafo grafo;
  int nro_reg;

  cout << "               ### Digite a quantidade de registros a serem lidos. ###" 
       << "\nOBS.: Dependendo da quantidade que for digitada o programa pode demorar para fazer os cálculos em todos registros."
       << "\nOBS.: O programa roda até 300.000 valores porém demora MUITO pra computar as respostas."
       << "\n\nDigite um valor recomendado(entre 300 a 50.000): ";
  cin >> nro_reg;

  InsereRegistros(&grafo, nro_reg);

  cout << "Calculando anomalias, aguarde..." << endl;

  grafo.CalculateForest(nro_reg);
  grafo.ImprimirGrafo();

  cout << "### Role a tela pra cima para ver o resultado encontrado. ###" << endl;

	return 0;
}
