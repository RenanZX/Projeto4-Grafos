#include "tree.hpp"

Node::Node(Deputy dado){
	deputado = dado;
	right = NULL;
	left = NULL;
	level_left = 0;
	level_right = 0;
}

Tree::Tree(){
	root = NULL;
	split_attribute = -1;
}

Tree::Tree(int split_attr,std::vector<Deputy> data,int limit_height){
	root = NULL;
	split_attribute = split_attr;
	iTree(data,limit_height);
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
	if(split_attribute!=-1){
		switch(split_attribute){
			case DEP_NAME:
				if(data.deputy_name < leaf->deputado.deputy_name){
					return true;
				}
			break;
			case ESTATE:
				if(data.estate < leaf->deputado.estate){
					return true;
				}
			break;
			case PARTY:
				if(data.party < leaf->deputado.party){
					return true;
				}
			break;
			case REFOUND_DESCRIPTION:
				if(data.refound_description < leaf->deputado.refound_description){
					return true;
				}
			break;
			case COMPANY_NAME:
				if(data.company_name < leaf->deputado.company_name){
					return true;
				}
			break;
			case COMPANY_ID:
				if(data.company_id < leaf->deputado.company_id){
					return true;
				}
			break;
			case REFUND_DATE:
				if(data.refund_date < leaf->deputado.refund_date){
					return true;
				}
			break;
			case REFUND_VALUE:
				if(data.refund_value < leaf->deputado.refund_value){
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

int Tree::PathLength(Node* no,int current_length){
	if(no==NULL){
		return current_length;
	}
	
	if((no->right==NULL)&&(no->left==NULL)){
		PathAnomally.push_back(no->deputado);
		return current_length;
	}
	
	if(no->level_right < no->level_left){
		return PathLength(no->left,current_length+1);
	}
	return PathLength(no->right,current_length+1);
}

int Tree::PathLength(int current_length){
	return PathLength(root,current_length);
}


void Tree::iTree(std::vector<Deputy> X,int limit_height){
	if(root == NULL){
		int split_value = X.size()/2;
		root = new Node(X[split_value]);
	}
	for(int i=0;i<(signed)X.size();i++){
		Insert(X[i]);
	}
	if((root->level_right > limit_height)||(root->level_left > limit_height)){
		root->deputado.anomally = true;
	}
}

Forest::Forest(){
	
}

void Forest::putTree(Tree *tree){
	set_of_tree.push_back(tree);
}

std::vector<Deputy> Forest::sample(std::vector<Deputy> X, int sub_sample){
	std::size_t const size = ceil(X.size()/sub_sample);
	if(lastIndex != (signed)X.size()){
		std::vector<Deputy> split(lastbegin,lastbegin+size);
		lastbegin = lastbegin+size;
		lastIndex = lastIndex+size;
		return split;
	}
	return std::vector<Deputy>();
}

void Forest::initialize_VectorAtt(){
	for(int j=7;j>0;j--){
		atributos.push_back(j);
	}
}

int Forest::PathLengthLonger(int x){
	int maior = 0;
	int corrente = 0;

	for(int i=0;i<signed(set_of_tree.size());i++){
		if(x == set_of_tree[i]->split_attribute){
			corrente = set_of_tree[i]->PathLength();
			if(corrente > maior){
				maior = corrente;
				pathAnomaly = set_of_tree[i]->PathAnomally;
			}
		}
	}
	return maior;
}

void Forest::setSplitAtt(){
	if(atributos.size()==0){
		initialize_VectorAtt();
	}
	split_attribute = atributos.back();
	atributos.pop_back();
}

void Forest::reset_AttVector(){
	for(int j=7;j<0;j--){
		atributos.push_back(j);
	}
}

Tree* Forest::iTree(std::vector<Deputy> X,int limit_height){
	Tree *tree = new Tree();
	tree->split_attribute = split_attribute;
	tree->iTree(X,limit_height);
	return tree;
}

std::vector<Deputy> Forest::PathAnomally(){
	return pathAnomaly;
}

void Forest::iForest(std::vector<Deputy> X,int trees,int sub_sample){
	std::vector<Deputy> Y;
	int i =1,j=0;
	int limit_height = ceil(log2(sub_sample));
	lastbegin = X.begin();
	lastIndex = 0;
	Y = sample(X,sub_sample);

	while((i<trees)&&(!Y.empty())){
		setSplitAtt();
		if(!Y.empty()){
			putTree(iTree(Y,limit_height));
			if(j >= 8){
				reset_AttVector();
				j=0;
			}
			j++;
		}
		Y = sample(X,sub_sample);
		i++;
	}
}