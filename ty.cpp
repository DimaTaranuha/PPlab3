#include <iostream>
#include <stdio.h>
#include <ctime>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Node{
	int value;
	Node *left;
	Node *right;
};

Node *root; 


void insertTree(Node **aNode, int data){
	if (!(*aNode)){		
		(*aNode) = new Node;
		(*aNode)->value = data;
		(*aNode)->left = NULL;
		(*aNode)->right = NULL;
	}
	else{
	if (data < (*aNode)->value) insertTree(&(*aNode)->left,data);
	else insertTree(&(*aNode)->right, data);
	}
	return;
}

void printTree(Node *aNode){ 
	if (aNode){
		printTree(aNode->left);
		cout<<aNode->value<<"  ";
		printTree(aNode->right);
	}
	return;
}

int getDepth(Node *tree, int depth) {
if (tree == NULL)
return depth;
return max(getDepth(tree->left, depth + 1), getDepth(tree->right, depth + 1));
}

int main(){
	srand(time(NULL));
	setlocale(LC_CTYPE,"rus");
	for(int i = 0;i < 10;i++){
		insertTree(&root,rand() % 50 - 25);
	}
	cout << "Елементи дерева: " << endl;	
	printTree(root);
	cout << endl << endl << "Глибина дерева  = " << getDepth(root,0) << endl;
	cout << endl;
	system("pause");
}
