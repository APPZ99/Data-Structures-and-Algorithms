#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int data;
	struct node *next; 
}node;

typedef struct queue{
	node *front;
	node *rear;
}queue;

//��ʼ�����
node *init_node(){
    node *n=(node*)malloc(sizeof(node));
    if(n==NULL){    //����ʧ�ܣ��˳�
        exit(0);
    }
    return n;
}

//��ʼ������
queue *init_queue(){
    queue *q=(queue*)malloc(sizeof(queue));
    if(q==NULL){    //����ʧ�ܣ��˳�
        exit(0);
    }
    //ͷβ������ֵNULL
    q->front=NULL;  
    q->rear=NULL;
    return q;
}

//�����п�
int empty(queue *q){
    if(q->front==NULL){
        return 1;   //1--��ʾ�棬˵�����п�
    }else{
        return 0;   //0--��ʾ�٣�˵�����зǿ�
    }
}

// ���
void push(queue *q, int data){
	node *n = init_node();
	n->data = data;
	n->next = NULL;
	
	if(empty(q)){
		q->front = n;
		q->rear = n;
	}
	else{
		q->rear->next = n;
		q->rear = n;
	}
}

// ����
void pop(queue *q){
	node *n = q->front ;
	
	if(empty(q)){
		return;
	}
	if(q->front == q->rear){
		q->front = NULL;
		q->rear = NULL;
		free(n);
	}
	else{
		q->front = q->front->next ;
		free(n);
	}
} 

//��ӡ����Ԫ��
void print_queue(queue *q){
    node *n = init_node();
    n=q->front;
    if(empty(q)){
        return ;    //��ʱ����Ϊ�գ�ֱ�ӷ��غ�������
    }
    while (n!=NULL){
        printf("%d\t",n->data);
        n=n->next;
    }
    printf("\n");   //�ǵû���
}

int main(){
    queue *q=init_queue();
    ///////////////��Ӳ���/////////////////
    printf("���\n");
    for(int i=1;i<=5;i++){
        push(q,i);
        print_queue(q);
    }
    ///////////////���Ӳ���/////////////////
    printf("����\n");
    for(int i=1;i<=5;i++){
        pop(q);
        print_queue(q);
    }
    return 0;
}





























 
