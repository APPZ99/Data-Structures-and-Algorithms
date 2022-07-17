#include <stdio.h>
#include <stdlib.h>

typedef int Status;

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

Status SearchBST(BiTree t, int key, BiTree f, BiTree *p){
	if(!t){
		*p = f;
		return FALSE;
	}
	else if(key == t->data){
		*p = t;
		return TRUE;
	}
	else if(key < t->data){
		return SearchBST(t->lchild, key, t, p);
	}
	else{
		return SearchBST(t->rchild, key, t, p);
	}
}


/*
struct BiTree {
    int data;
    BiTree *lchild;
    BiTree *rchild;
};
  
//�ڶ����������в�����ҹؼ���key
BiTree* InsertBST(BiTree *t,int key)
{
    if (t == NULL)
    {
        t = new BiTree();
        t->lchild = t->rchild = NULL;
        t->data = key;
        return t;
    }
  
    if (key < t->data) 
        t->lchild = InsertBST(t->lchild, key);
    else
        t->rchild = InsertBST(t->rchild, key);
  
    return t;
}
  
//n������������d�У�treeΪ������������
BiTree* CreateBiTree(BiTree *tree, int d[], int n)
{
    for (int i = 0; i < n; i++)
        tree = InsertBST(tree, d[i]);
}

*/

Status DeleteBST(BiTree *T,int key)
{ 
    if(!*T) /* �����ڹؼ��ֵ���key������Ԫ�� */ 
        return FALSE;
    else
    {
        if (key==(*T)->data) /* �ҵ��ؼ��ֵ���key������Ԫ�� */ 
            return Delete(T);
        else if (key<(*T)->data)
            return DeleteBST(&(*T)->lchild,key);
        else
            return DeleteBST(&(*T)->rchild,key);
  
    }
}

Status Delete(BiTree *p){
	
	BiTree q, s;
	if((*p)->rchild == NULL){
		q = *p;
		*p = (*p)->lchild;
		free(q);
	} 
	else if((*p)->lchild == NULL){
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else{
		q = *p;
		s = (*p)->lchild;
		while(s->rchild){
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if(q != *p){
			q->rchild = s->lchild;
		}
		else{
			q->lchild = s->lchild;
		}
		free(s);
	}
	return TRUE;
		
}































