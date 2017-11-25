#include "grafos.hpp"
#include "dados.hpp"

int main(){
  
  Grafo grafo;

  InsereRegistros(&grafo);
  grafo.CalculateForest(100000);
  grafo.ImprimirGrafo();

	return 0;
}
