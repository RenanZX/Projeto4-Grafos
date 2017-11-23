#include "tree.hpp"

const int Forest::DEP_NAME = 0;
const int Forest::ESTATE = 1;
const int Forest::PARTY = 2;
const int Forest::REFOUND_DESCRIPTION = 3;
const int Forest::COMPANY_NAME = 4;
const int Forest::COMPANY_ID = 5;
const int Forest::REFUND_DATE = 6;
const int Forest::REFUND_VALUE = 7;

const int Tree::DEP_NAME = 0;
const int Tree::ESTATE = 1;
const int Tree::PARTY = 2;
const int Tree::REFOUND_DESCRIPTION = 3;
const int Tree::COMPANY_NAME = 4;
const int Tree::COMPANY_ID = 5;
const int Tree::REFUND_DATE = 6;
const int Tree::REFUND_VALUE = 7;

Node::Node(Deputy dado){
	deputado = dado;
	right = NULL;
	left = NULL;
	split_attribute = -1;
	level_left = 0;
	level_right = 0;
}

Tree::Tree(){
	root = NULL;
}

void Tree::Destroy_tree(Node * no){
	if(no!=NULL){
		Destroy_tree(no->left);
		Destroy_tree(no->right);
		delete no;
	}
}

Tree::~Tree(){
	Destroy_tree(root);
}

bool Tree::TestNode(Deputy data,Node* leaf){
	if(leaf->split_attribute!=-1){
		switch(leaf->split_attribute){
			case DEP_NAME:
				if(data.deputy_name < leaf->deputy_name){
					return true;
				}
			break;
			case ESTATE:
				if(data.estate < leaf->estate){
					return true;
				}
			break;
			case PARTY:
				if(data.party < leaf->party){
					return true;
				}
			break;
			case REFOUND_DESCRIPTION:
				if(data.refound_description < leaf->refound_description){
					return true;
				}
			break;
			case COMPANY_NAME:
				if(data.company_name < leaf->company_name){
					return true;
				}
			break;
			case COMPANY_ID:
				if(data.company_id < leaf->company_id){
					return true;
				}
			break;
			case REFUND_DATE:
				if(data.refund_date < leaf->refund_date){
					return true;
				}
			break;
			case REFUND_VALUE:
				if(data.refund_value < leaf->refund_value){
					return true;
				}
			break;
		}
	}
	return false;
}

void Tree::Insert(Deputy data,Node* leaf){
	if(TestNode(data,leaf)){
		if(leaf->left!=NULL){
			Insert(data,leaf->left);
			leaf->level_left++;
		}else{
			leaf->left = new Node(data);
		}
	}else{
		if(leaf->right!=NULL){
			Insert(data,leaf->right);
			leaf->level_right++;
		}else{
			leaf->right = new Node(data);
		}
	}
}

void Tree::Insert_Leaf(Node* leaf,Node* local){
	if(TestNode(leaf->deputado,local)){
		if(local->left!=NULL){
			Insert_Leaf(leaf,local->left);
		}else{
			local->left = leaf;
		}
	}else{
		if(local->right!=NULL){
			Insert_Leaf(leaf,local->right);
		}else{
			local->right = leaf;
		}
	}
}

void Tree::Insert(Deputy data){
	if(root!=NULL){
		Insert(data,root);
	}else{
		root = new Node(data);
	}
}

void Tree::left(Tree tree){
	if(root!=NULL){
		if(root->left!=NULL){
			Insert_Leaf(tree.root,root->left);		
		}
	}
}

void Tree::right(Tree tree){
	if(root!=NULL){
		if(root->right!=NULL){
			Insert_Leaf(tree.root,root->right);		
		}
	}
}

int Tree::PathLength(int x,Node* no,int current_length){
	if(no==NULL){
		return 0;
	}
	if(no->split_attribute == x){
		current_length++;
	}
	if((no->right==NULL)&&(no->left==NULL)){
		return current_length;
	}
	if(no->level_right < no->level_left){
		return PathLength(x,no->left,current_length);
	}
	return PathLength(x,no->right,current_length);
}

int Tree::PathLength(int x,int current_length){
	return PathLength(x,root,current_length);
}

Forest::Forest(){
	int j = 7;
	for(int i=0;i<8;i++){
		atributos[i] = j;
		j--;
	}
}

void Forest::operator+(Tree tree){
	set_of_tree.push_back(tree);
}

void Forest::putTree(Tree tree){
	set_of_tree.push_back(tree);
}

bool Forest::Compare_Dep_Name(const Deputy& dep1,const Deputy& dep2){
	return dep1.deputy_name < dep2.deputy_name;
}

bool Forest::Compare_Estate(const Deputy& dep1,const Deputy& dep2){
	return dep1.estate < dep2.estate;
}

bool Forest::Compare_Party(const Deputy& dep1,const Deputy& dep2){
	return dep1.party < dep2.party;
}

bool Forest::Compare_Refound_description(const Deputy& dep1,const Deputy& dep2){
	return dep1.refound_description < dep2.refound_description;
}

bool Forest::Compare_Company_Name(const Deputy& dep1,const Deputy& dep2){
	return dep1.company_name < dep2.company_name;
}

bool Forest::Compare_Company_Id(const Deputy& dep1,const Deputy& dep2){
	return dep1.company_id < dep2.company_id;
}

bool Forest::Compare_Refund_date(const Deputy& dep1,const Deputy& dep2){
	return dep1.refund_date < dep2.refund_date;
}

bool Forest::Compare_Refund_value(const Deputy& dep1,const Deputy& dep2){
	return dep1.refund_value < dep2.refund_value;
}

std::vector<Deputy> Forest::Sort_Vector(std::vector<Deputy> X,int split){
	switch(split){
		case DEP_NAME:
			sort(X.begin(),X.end(),Compare_Dep_Name);
			break;
		case ESTATE:
			sort(X.begin(),X.end(),Compare_Estate);
			break;
		case PARTY:
			sort(X.begin(),X.end(),Compare_Party);
			break;
		case REFOUND_DESCRIPTION:
			sort(X.begin(),X.end(),Compare_Refound_description);
			break;
		case COMPANY_NAME:
			sort(X.begin(),X.end(),Compare_Company_Name);
			break;
		case COMPANY_ID:
			sort(X.begin(),X.end(),Compare_Company_Id);
			break;
		case REFUND_DATE:
			sort(X.begin(),X.end(),Compare_Refund_date);
			break;
		case REFUND_VALUE:
			sort(X.begin(),X.end(),Compare_Refund_value);
			break;
	}
	return X;
}

std::vector<Deputy> Forest::sample(std::vector<Deputy> X, int sub_sample){
	std::size_t const size = ceil(X.size()/sub_sample);
	std::vector<Deputy> split(X.begin(),X.begin()+size);
	return split;
}

std::vector<Deputy> Forest::filter_left(std::vector<Deputy> X,int limit){
	std::size_t const limited = limit;
	std::vector<Deputy> split_lo(X.begin(),X.begin()+limited);
	return split_lo;
}

std::vector<Deputy> Forest::filter_right(std::vector<Deputy> X,int limit){
	std::size_t const limited = limit;
	std::vector<Deputy> split_hi(X.begin()+limited,X.end());
	return split_hi;
}

Tree Forest::iTree(std::vector<Deputy> X,int current_height,int limit_height){
	Tree tree;
	if((current_height >= limit_height)&&(X.size() == 1)){
		tree.Insert(X.back());
		X.pop_back();
		return tree;
	}else{
		if(tree.root->split_attribute == -1){
			tree.root->split_attribute = split_attribute;
		}
		tree.root->split_value = X.size()/2;
		X = Sort_Vector(X,tree.root->split_attribute);
		std::vector<Deputy> Xl = filter_left(X,tree.root->split_value);
		std::vector<Deputy> Xr = filter_right(X,tree.root->split_value);
		tree.left(iTree(Xl,current_height+1,limit_height));
		tree.right(iTree(Xr,current_height+1,limit_height));
	}
	return tree;
}

int Forest::PathLengthLonger(int x){
	int maior = 0;
	int corrente = 0;

	for(int i=0;i<signed(set_of_tree.size());i++){
		corrente = set_of_tree[i].PathLength(x);
		if(corrente > maior){
			maior = corrente;
		}
	}
	return maior;
}

void Forest::iForest(std::vector<Deputy> X,int trees,int sub_sample){
	Tree tree;
	std::vector<Deputy> Y;
	int i =0;
	int limit_height = ceil(log2(sub_sample));
	for(i=1;i<trees;i++){
		split_attribute = atributos.back();
		atributos.pop_back();
		Y = sample(X,sub_sample);
		putTree(iTree(Y,0,limit_height));
	}
}