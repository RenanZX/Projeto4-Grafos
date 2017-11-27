#ifndef GRAFOS_H
#define GRAFOS_H
#include "tree.hpp"

using namespace std;

class Grafo{
private:
  std::vector<Deputy> lista_v; /*lista de vertices do grafo*/
  std::vector<string>Names;
  std::vector<string>States;
  std::vector<string>Party;
  std::vector<string>Refound_Descriptions;
  std::vector<string>Company_names;
  std::vector<double>Company_ids;
  std::vector<string>Refound_Dates;
  std::vector<int>Refound_Values;
  Tree tree;
  Forest forest;
  void Sort_Vectors();
  void find_anomally();/*encontra as anomalias*/
  void ImprimirDadosAnomalos(); /*Imprime as anomalias dependendo da instancia*/
public:
  Grafo(); /*construtor e destrutor do grafo*/
  ~Grafo();
  void InsereVertice(Deputy deputado); /*Insere os vertices no grafo contendo os deputados*/
  void CalculateForest(int limit_trees = 100,int limite = 50); /*calcula a floresta e recebe um limite como parametro*/
  void ImprimirGrafo(); /*imprime o grafo*/
};

#endif