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

//初始化结点
node *init_node(){
    node *n=(node*)malloc(sizeof(node));
    if(n==NULL){    //建立失败，退出
        exit(0);
    }
    return n;
}

//初始化队列
queue *init_queue(){
    queue *q=(queue*)malloc(sizeof(queue));
    if(q==NULL){    //建立失败，退出
        exit(0);
    }
    //头尾结点均赋值NULL
    q->front=NULL;  
    q->rear=NULL;
    return q;
}

//队列判空
int empty(queue *q){
    if(q->front==NULL){
        return 1;   //1--表示真，说明队列空
    }else{
        return 0;   //0--表示假，说明队列非空
    }
}

// 入队
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

// 出队
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

//打印队列元素
void print_queue(queue *q){
    node *n = init_node();
    n=q->front;
    if(empty(q)){
        return ;    //此时队列为空，直接返回函数结束
    }
    while (n!=NULL){
        printf("%d\t",n->data);
        n=n->next;
    }
    printf("\n");   //记得换行
}

int main(){
    queue *q=init_queue();
    ///////////////入队操作/////////////////
    printf("入队\n");
    for(int i=1;i<=5;i++){
        push(q,i);
        print_queue(q);
    }
    ///////////////出队操作/////////////////
    printf("出队\n");
    for(int i=1;i<=5;i++){
        pop(q);
        print_queue(q);
    }
    return 0;
}





























 
