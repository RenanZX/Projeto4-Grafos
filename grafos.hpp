#ifndef GRAFOS_H
#define GRAFOS_H
#include "tree.hpp"

using namespace std;

class Grafo{
private:
  std::vector<Deputy> lista_v; /*lista de vertices do grafo*/
  std::vector<int> anomalies;
  std::vector<std::vector<Deputy> >AnomaliePaths;/*todos os caminhos anomalos encontrados*/
  Tree tree;
  Forest forest;
  void find_anomally();/*encontra as anomalias*/
  void ImprimirInstanciaAnomala(int x); /*Imprime as anomalias dependendo da instancia*/
public:
  Grafo(); /*construtor e destrutor do grafo*/
  ~Grafo();
  void InsereVertice(Deputy deputado); /*Insere os vertices no grafo contendo os deputados*/
  void CalculateForest(int limite); /*calcula a floresta e recebe um limite como parametro*/
  void ImprimirGrafo(); /*imprime o grafo*/
};

#endif