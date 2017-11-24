#include "grafos.hpp"
#include "dados.hpp"

int main(){
  
  Grafo grafo;

  InsereRegistros(&grafo);
  //grafo.CalculateForest();
  grafo.ImprimirGrafo();
	return 0;
}
