#ifndef TREE_H
#define TREE_H
#include <bits/stdc++.h>

using namespace std;

typedef struct{
  string deputy_name;
  string estate;
  string party;
  string refound_description;
  string company_name;
  double company_id;
  string refund_date;
  int refund_value;
  int annomally;
}Deputy;

class Node{
friend class Tree;
private:
  Node(Deputy dado);
  Deputy deputado;
  Node *right;
  Node *left;
public:
  int split_attribute;
  int split_value;
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
  Node *root;
  void Insert(Deputy data,Node* leaf);
  void Insert_Leaf(Node* leaf,Node* local);
  void Destroy_tree(Node *no);
public:
  Tree();
  ~Tree();
  void Insert(Deputy data);
  void left(Tree tree);
  void right(Tree tree);
  int PathLength(int x,Node* no,int current_length);
};

class Forest{
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
  std::vector<Deputy> filter_left(std::vector<Deputy> X,int limit);
  std::vector<Deputy> filter_right(std::vector<Deputy> X,int limit);
  std::vector<Deputy> Sort_Vector(std::vector<Deputy> X);
  int split_attribute;
  int split_value;
  std::vector<Tree> set_of_tree;
  std::vector<Deputy> sample(std::vector<Deputy> X, int sub_sample);
public:
  Forest();
  void operator+(Tree tree);
  void putTree(Tree tree);
  Tree iTree(std::vector<Deputy> X,int current_height,int limit_height);
  void iForest(std::vector<Deputy> X,int trees,int sub_sample = 256);
};

#endif