#include <cstdlib>
#include <stdio.h>
#include <iostream>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}Node;

typedef struct {
	Node* root;
}Tree;

// ����-��������
void insert(Tree* tree, int value){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	
	if(tree->root == NULL){
		tree->root = node;
	}
	else{
		Node* temp = tree->root ;
		while(temp != NULL){
			if(value < temp->data){
				if(temp->left == NULL){
					temp->left = node;
					return;
				}
				else{
					temp = temp->left;
				}
			else{
				if(temp->right == NULL){
					temp->right = node;
					return;
				}
				else{
					temp = temp->right ;
				}
			}
			}
		}
	}
	return;
} 

// ���������
void inorder(Node* node){
	if(node != NULL){
		inorder(node->left);
		printf("%d", node->data);
		inorder(node->right);
	}
} 

// ��������� 
void preorder(Node* node){
    if (node != NULL)
    {
        printf("%d ",node->data);
        inorder(node->left);
        inorder(node->right);
    }
}

// ���������� 
void postorder(Node* node){
    if (node != NULL)
    {
        inorder(node->left);
        inorder(node->right);
        printf("%d ",node->data);
    }
}

int main(){
    Tree tree;
    tree.root = NULL;//����һ������
    int n;
    scanf("%d",&n);
  
    //����n���������������
    for (int i = 0; i < n; i++){
        int temp;
        scanf("%d",&temp);
        insert(&tree, temp);
    }
  
    inorder(tree.root);//�������
  
    return 0;
}
































