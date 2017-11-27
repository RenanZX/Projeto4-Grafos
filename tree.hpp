#ifndef TREE_H
#define TREE_H
#include <bits/stdc++.h>
#include <tr1/memory>

using namespace std;
/*constantes referentes a um atributo da struct deputado*/
const int DEP_NAME = 0;
const int ESTATE = 1;
const int PARTY = 2;
const int REFOUND_DESCRIPTION = 3;
const int COMPANY_NAME = 4;
const int COMPANY_ID = 5;
const int REFUND_DATE = 6;
const int REFUND_VALUE = 7;

typedef struct deputy{
  string deputy_name;
  string estate;
  string party;
  string refound_description;
  string company_name;
  string company_id;
  string refund_date;
  float refund_value;
  bool anomally;
  bool operator!=(const struct deputy& v2){
    if((deputy_name != v2.deputy_name)&&(estate != v2.estate)&&
      (party != v2.party)&&(refound_description!=v2.refound_description)&&
      (company_name!=v2.company_name)&&(company_id!=v2.company_id)&&
      (refund_date!=v2.refund_date)&&(refund_value!=v2.refund_value)){
      return true;
    }
    return false;
  }
}Deputy;/*struct deputado e suas instancias*/

class Node{/*nodo da arvore*/
friend class Tree;
private:
  Node(Deputy dado);/*construtor do nodo*/
  Deputy deputado;/*informacao contida no nodo*/
  Node *right;/*referencia para o proximo elemento*/
  Node *left;
  int level_right;/*níveis das subarvores geradas(direita e esquerda)*/
  int level_left;
};

class Tree{
friend class Forest;
private:
  Node *root;/*raiz da arvore*/
  int split_attribute; /*atributo de divisao da arvore*/
  std::vector<Deputy>PathAnomally; /*caminho anomalo*/
  void Insert(Deputy data,Node* leaf); /*Inserção de dados na arvore*/
  void Insert_Leaf(Node* leaf,Node* local); /*inserção de nodos na arvore*/
  void Destroy_tree(Node *no); /*destrutor da arvore*/
  int PathLength(Node* no,int current_length); /*calcula o tamanho do caminho a partir de um nodo e retorna um int*/
  bool TestNode(Deputy data, Node* leaf); /*testa o nodo*/
public:
  Tree(); /*construtor da arvore*/
  Tree(int split_attr,std::vector<Deputy> data,int limit_height);
  ~Tree();/*destrutor*/
  void Insert(Deputy data);
  int PathLength(int current_length = 0);/*tamanho do caminho*/
  void iTree(std::vector<Deputy> X,int limit_height); /*função iTree isola dados a partir de um vetor X*/
};

class Forest{
private:
  int split_value;/*valores para o critério de divisão das arvores*/
  int split_attribute;
  vector<Deputy>::iterator lastbegin;
  int lastIndex;
  std::vector<int> atributos;
  std::vector<Tree*> set_of_tree; /*quantidade de arvores dentro da floresta*/
  void setSplitAtt();
  void initialize_VectorAtt();
  void reset_AttVector();
  std::vector<Deputy> pathAnomaly;/*caminho anormal*/
  std::vector<Deputy> sample(std::vector<Deputy> X, int sub_sample);/*gera um sub-vetor apartir de X*/
  Tree* iTree(std::vector<Deputy> X,int limit_height); /*funcao iTree*/
public:
  Forest(); /*construtor da floresta*/
  void putTree(Tree *tree); /*Insere arvores na floresta*/
  void iForest(std::vector<Deputy> X,int trees,int sub_sample = 256); /*função Iforest,isola um conjunto de arvores a partir de uma massa de dados X*/
  int PathLengthLonger(int x); /*pega o maior caminho a partir de uma instancia x da struct deputy*/
  std::vector<Deputy> PathAnomally(); /*retorna o caminho anormal*/
};

#endif