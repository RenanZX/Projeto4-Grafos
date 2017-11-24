#ifndef TREE_H
#define TREE_H
#include <bits/stdc++.h>
#include <tr1/memory>

using namespace std;

typedef struct deputy{
  string deputy_name;
  string estate;
  string party;
  string refound_description;
  string company_name;
  double company_id;
  string refund_date;
  int refund_value;
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
}Deputy;

class Node{
friend class Tree;
private:
  Node(Deputy dado);
  Deputy deputado;
  Node *right;
  Node *left;
  int level_right;
  int level_left;
};

class Tree{
friend class Forest;
private:
  static const int DEP_NAME;
  static const int ESTATE;
  static const int PARTY;
  static const int REFOUND_DESCRIPTION;
  static const int COMPANY_NAME;
  static const int COMPANY_ID;
  static const int REFUND_DATE;
  static const int REFUND_VALUE;
  static bool Compare_Dep_Name(const Deputy& dep1,const Deputy& dep2);
  static bool Compare_Estate(const Deputy& dep1,const Deputy& dep2);
  static bool Compare_Party(const Deputy& dep1,const Deputy& dep2);
  static bool Compare_Refound_description(const Deputy& dep1,const Deputy& dep2);
  static bool Compare_Company_Name(const Deputy& dep1,const Deputy& dep2);
  static bool Compare_Company_Id(const Deputy& dep1,const Deputy& dep2);
  static bool Compare_Refund_date(const Deputy& dep1,const Deputy& dep2);
  static bool Compare_Refund_value(const Deputy& dep1,const Deputy& dep2);
  Node *root;
  int split_attribute;
  std::vector<Deputy>PathAnomally;
  void Insert(Deputy data,Node* leaf);
  void Insert_Leaf(Node* leaf,Node* local);
  void Destroy_tree(Node *no);
  int PathLength(Node* no,int current_length);
  bool TestNode(Deputy data, Node* leaf);
public:
  Tree();
  Tree(int split_attr,std::vector<Deputy> data,int limit_height);
  ~Tree();
  void Insert(Deputy data);
  void left(Tree tree);
  void right(Tree tree);
  int PathLength(int current_length = 0);
  void iTree(std::vector<Deputy> X,int limit_height);
  int getSideAnomally();
};

class Forest{
private:
  int split_value;
  int split_attribute;
  vector<Deputy>::iterator lastbegin;
  int lastIndex;
  std::vector<int> atributos;
  std::vector<Tree*> set_of_tree;
  void setSplitAtt();
  void initialize_VectorAtt();
  void reset_AttVector();
  std::vector<Deputy> pathAnomaly;
  std::vector<Deputy> sample(std::vector<Deputy> X, int sub_sample);
  Tree* iTree(std::vector<Deputy> X,int limit_height);
public:
  Forest();
  //void operator+(Tree tree);
  void putTree(Tree *tree);
  void iForest(std::vector<Deputy> X,int trees,int sub_sample = 256);
  int PathLengthLonger(int x);
  std::vector<Deputy> PathAnomally();
};

#endif