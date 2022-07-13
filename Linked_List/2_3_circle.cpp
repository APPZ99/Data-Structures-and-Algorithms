#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int data;
    struct list *next;
}list;


list *initlist(){
    list *head=(list*)malloc(sizeof(list));
    if(head==NULL){
        printf("创建失败，退出程序");
        exit(0);
    }else{
        head->next=NULL;
        return head;
    }
}

// 创建-插入操作
int insert_list(list *head){
	int data;
	printf("请输入要插入的元素：");
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
		printf("头结点已无元素\n");
        return 0;
	}
}

// 插入操作
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
 
 // 删除操作
 int delete_list(list *head){
 	if(head == NULL) {
        printf("链表为空！\n");
        return 0;
    }
    
    list *temp = head;
    list *ptr = head->next ;
    
    int del;
    printf("请输入你要删除的元素：");
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

// 遍历操作 
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
        printf("头结点为空!\n");
        return 0;
    }
}

int main(){
    //////////初始化头结点//////////////
    list *head=initlist();
    head->next=head;
    ////////通过插入元素完善链表/////////
    for(int i=0;i<5;i++){   //只是演示使用，不具体提供输入
        create_list(head);
    }
    display(head);
    ////////////插入元素////////////////
    head=insert_list(head,1,10);
    display(head);
    ////////////删除元素////////////////
    delete_list(head);
    display(head);
    return 0;
}






























