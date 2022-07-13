#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int data;
    struct list *next;
}list;


list *initlist(){
    list *head=(list*)malloc(sizeof(list));
    if(head==NULL){
        printf("����ʧ�ܣ��˳�����");
        exit(0);
    }else{
        head->next=NULL;
        return head;
    }
}

// ����-�������
int insert_list(list *head){
	int data;
	printf("������Ҫ�����Ԫ�أ�");
    scanf("%d",&data);
    
    list *node = initlist();
    node->data = data;
    
    if(head != NULL){
    	list *p = head;
    	while(p->next != head){
    		p = p->next;
		}
		p->next = node;
		node->next = head;
		return 1l
	}
	else{
		printf("ͷ�������Ԫ��\n");
        return 0;
	}
}

// �������
 list* insert_list(list *head, int pos, int data){
 	list *node = initlist();
 	list *p = head;
 	list *t;
 	t = p;
 	node->data = data;
 	
 	if(head != NULL){
 		for(int i = 1; i < pos; i++){
 			t = t->next ;
		 }
		node->next = t->next ;
		t->next = node;
		return p;
	 }
	 return p;
 }
 
 // ɾ������
 int delete_list(list *head){
 	if(head == NULL) {
        printf("����Ϊ�գ�\n");
        return 0;
    }
    
    list *temp = head;
    list *ptr = head->next ;
    
    int del;
    printf("��������Ҫɾ����Ԫ�أ�");
    scanf("%d",&del);
    
    while(ptr != head){
    	if(ptr->data  == del){
    		if(ptr->next == head){
    			temp->next = head;
    			free(ptr);
    			return 1;
			}
			temp->next = ptr->next ;
			free(ptr);
			return 1;
		}
		temp = temp->next ;
		ptr = ptr->next ;
	}
	return 0;
 } 

// �������� 
int display(list *head) {
    if(head != NULL) {
        list *p  = head;
        while(p->next != head ) {
            printf("%d   ",p->next->data);
            p = p->next;
        }
        printf("\n");   
        return 1;
    } else {
        printf("ͷ���Ϊ��!\n");
        return 0;
    }
}

int main(){
    //////////��ʼ��ͷ���//////////////
    list *head=initlist();
    head->next=head;
    ////////ͨ������Ԫ����������/////////
    for(int i=0;i<5;i++){   //ֻ����ʾʹ�ã��������ṩ����
        create_list(head);
    }
    display(head);
    ////////////����Ԫ��////////////////
    head=insert_list(head,1,10);
    display(head);
    ////////////ɾ��Ԫ��////////////////
    delete_list(head);
    display(head);
    return 0;
}






























