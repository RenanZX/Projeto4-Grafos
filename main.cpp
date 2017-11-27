#include "grafos.hpp"
#include "dados.hpp"

int main(){
  
  Grafo grafo;
  int nro_reg;

  cout << "Digite a quantidade de registros a serem lidos: ";
  cin >> nro_reg;

  InsereRegistros(&grafo, nro_reg);

  cout << "Calculando anomalias, aguarde..." << endl;

  grafo.CalculateForest(nro_reg);
  grafo.ImprimirGrafo();

	return 0;
}
