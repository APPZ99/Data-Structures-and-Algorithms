#include <stdio.h>
#include <stdlib.h>

typedef struct line{
	int data;
	struct line *pre;
	struct line *next;
}line, *a;

line* initline(line* head){
	int number, pos = 1, input_data;
	printf("���봴������С\n");
	scanf("%d", &number);
	
	if(number < 1){
		return NULL;
	}
	
	head = (line*)malloc(sizeof(line));
	head->pre = NULL;
	head->next = NULL;
	
	printf("�����%d������\n", pos++);
	scanf("%d", &input_data);
	head->data = input_data;
	
	line *list = head;
	while(pos <= number){
		line *body = (line*)malloc(sizeof(line));
		body->pre = NULL;
		body->next = NULL;
		printf("�����%d������\n", pos++);
		scanf("%d", &input_data);
		body->data = input_data;
		
		list->next = body;
		body->pre  = list;
		list = list->next ;
	} 
	return head;
}

// �������
line* insertLine(line *head, int data, int add){
	line *temp = (line*)malloc(sizeof(line));
	temp->data  = data;
	temp->next = NULL;
	temp->pre = NULL;
	
	if(add == 1){
		temp->next = head;
		head->pre = temp;
		head = temp;
	}
	else{
		line *body = head;
		for(int i = 1; i < add-1; i++){
			body = body->next ;
		}
		if(body->next == NULL){
			body->next = temp;
			temp->pre = body;
		}
		else{
			body->next->pre = temp;
			temp->next = body->next ;
			body->next = temp;
			temp->pre = body; 
		}
	}
	return head;
} 

// ɾ������
line* deleteLine(line *head, int data){
	line *list = head;
	
	while(list){
		if(list->data == data){
			list->pre->next = list->next ;
			list->next->pre = list->pre;
			free(list);
			printf("success\n");
			return head;
		}
		list = list->next ;
	}
	printf("Not find");
	return head;
} 

// ����
void printLine(line *head){
    line *list = head;
    int pos=1;
    while(list){
        printf("��%d��������:%d\n",pos++,list->data);
        list=list->next;
    }
} 

int main(){
    line *head=NULL;
    printf("����˫�������\n"); 
    head=initLine(head);
    printLine(head);
//////////create line////////////
    printf("�������\n"); 
    head=insertLine(head,40,2);     //Ϊ�˼�ֱ��д������
    printLine(head);
//////////insert Line////////////
    printf("ɾ������\n"); 
    head=deleteLine(head,2);       //Ϊ�˼�ֱ��д������
    printLine(head);
//////////delete Line////////////  
    return 0;
}





























