#include <stdio.h>
#include <stdlib.h>

 
 typedef struct Node{
 	int data;
 	struct Node *next;
 }Node, *LinkedList;
 
 
 LinkedList listinit(){
 	Node *L;
 	L = (Node*) malloc(sizeof(Node));
 	if(L == NULL){
 		printf("申请空间失败"); 
	 }
	 L->next = NULL;
 }
 
 // 头插法
 LinkedList LinkedListCreatH(){
 	Node *L;
 	L = (Node*) malloc(sizeof(Node));
 	L->next = NULL;
 	
 	int x;
 	while(scanf("%d", &x) != EOF){
 		Node *p;
 		p = (Node*) malloc(sizeof(Node));
 		p->data = x;
 		p->next = L->next;
 		L->next = p;
	 }
	 
	 return L;
 } 
 
 // 尾插法
 LinkedList LinkedListCreatT(){
 	Node *L;
 	L = (Node*)malloc(sizeof(Node));
 	L->next = NULL;
 	Node *r;  // 这里需要有一个尾指针指向尾结点 
 	r = L;
 	
 	int x;
 	while(scanf("%d", &x) != EOF){
 		Node *p;
 		p = (Node*) malloc(sizeof(Node));
 		p->data = x;
 		r->next = p;
 		r = p;
	 }
	 r->next = NULL;
	 return L;
 } 
 
 // 遍历输出单链表
 void printList(LinkedList L){
 	Node *p = L->next;
 	int i = 0;
 	while(p){
 		printf("第%d个元素的值为：%d\n", ++i, p->data);
 		p = p->next;
	 }
 } 
 
 //修改单链表的值
 LinkedList LinkedListReplace(LinkedList L, int x, int k){
 	Node *p = L->next;
	int i = 0;
	while(p){
		if(p->data == x){
			p->data = k;
		}
		p = p->next;
	} 
	return L;
 } 
 
 // 单链表插入
 LinkedList LinkedListInsert(LinkedList L, int i, int x){
 	Node *pre;
 	pre = L;
 	int tempi = 0;
 	for(tempi = 1; tempi < i; tempi++){
 		pre = pre->next ;
	 }
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	p->data = x;
	p->next =pre->next;
	pre->next = p;
	
	return L;
 }
 
 // 单链表删除
 LinkedList LinkedListDelete(LinkedList L, int x){
 	Node *p, *pre;
 	p = L->next ;
 	
 	while(p->data != x){
 		pre = p;
 		p = p->next ;
	 }
	 pre->next = p->next ;
	 free(p);
	 
	 return L;
 } 
 
 int main() {
    //创建 
    LinkedList list;
    printf("请输入单链表的数据：以EOF结尾\n");
    list = LinkedListCreatH();
    //list=LinkedListCreatT();
    printList(list);
     
    //插入 
    int i;
    int x;
    printf("请输入插入数据的位置：");
    scanf("%d",&i);
    printf("请输入插入数据的值：");
    scanf("%d",&x);
    LinkedListInsert(list,i,x);
    printList(list);
     
    //修改
    printf("请输入修改的数据：");
    scanf("%d",&i);
    printf("请输入修改后的值：");
    scanf("%d",&x);
    LinkedListReplace(list,i,x);
    printList(list);
     
    //删除 
    printf("请输入要删除的元素的值：");
    scanf("%d",&x);
    LinkedListDelete(list,x);
    printList(list);
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
