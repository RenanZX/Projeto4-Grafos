#ifndef GRAFOS_H
#define GRAFOS_H
#include "tree.hpp"
using namespace std;

class Grafo{
private:
  std::vector<Deputy> lista_v; /*lista de vertices do grafo*/
  Tree tree;
  Forest forest;
  string anomally_found();
public:
  Grafo(); /*construtor e destrutor do grafo*/
  ~Grafo();
  void InsereVertice(Deputy deputado);
  void CalculateForest();
  void ImprimirGrafo(); /*imprime o grafo*/
};

#endif