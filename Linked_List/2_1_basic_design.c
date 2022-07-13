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
 		printf("����ռ�ʧ��"); 
	 }
	 L->next = NULL;
 }
 
 // ͷ�巨
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
 
 // β�巨
 LinkedList LinkedListCreatT(){
 	Node *L;
 	L = (Node*)malloc(sizeof(Node));
 	L->next = NULL;
 	Node *r;  // ������Ҫ��һ��βָ��ָ��β��� 
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
 
 // �������������
 void printList(LinkedList L){
 	Node *p = L->next;
 	int i = 0;
 	while(p){
 		printf("��%d��Ԫ�ص�ֵΪ��%d\n", ++i, p->data);
 		p = p->next;
	 }
 } 
 
 //�޸ĵ������ֵ
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
 
 // ���������
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
 
 // ������ɾ��
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
    //���� 
    LinkedList list;
    printf("�����뵥��������ݣ���EOF��β\n");
    list = LinkedListCreatH();
    //list=LinkedListCreatT();
    printList(list);
     
    //���� 
    int i;
    int x;
    printf("������������ݵ�λ�ã�");
    scanf("%d",&i);
    printf("������������ݵ�ֵ��");
    scanf("%d",&x);
    LinkedListInsert(list,i,x);
    printList(list);
     
    //�޸�
    printf("�������޸ĵ����ݣ�");
    scanf("%d",&i);
    printf("�������޸ĺ��ֵ��");
    scanf("%d",&x);
    LinkedListReplace(list,i,x);
    printList(list);
     
    //ɾ�� 
    printf("������Ҫɾ����Ԫ�ص�ֵ��");
    scanf("%d",&x);
    LinkedListDelete(list,x);
    printList(list);
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
