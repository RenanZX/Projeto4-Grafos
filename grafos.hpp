#ifndef GRAFOS_H
#define GRAFOS_H
#include "tree.hpp"

using namespace std;

class Grafo{
private:
  static const int DEP_NAME;
  static const int ESTATE;
  static const int PARTY;
  static const int REFOUND_DESCRIPTION;
  static const int COMPANY_NAME;
  static const int COMPANY_ID;
  static const int REFUND_DATE;
  static const int REFUND_VALUE;
  std::vector<Deputy> lista_v; /*lista de vertices do grafo*/
  std::vector<int> anomalies;
  std::vector<std::vector<Deputy> >AnomaliePaths;
  Tree tree;
  Forest forest;
  void find_anomally();
  void ImprimirInstanciaAnomala(int x);
public:
  Grafo(); /*construtor e destrutor do grafo*/
  ~Grafo();
  void InsereVertice(Deputy deputado);
  void CalculateForest(int limite);
  void ImprimirGrafo(); /*imprime o grafo*/
};

#endif