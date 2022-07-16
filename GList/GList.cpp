#include<iostream>
#include<cstdio>
#include<cstring>

#define AtomType int

typedef enum{ATOM, LIST}ElemTag;

typedef struct GLNode{
	ElemTag tag;
	union{
		AtomType atom;
		struct{
			struct GLNode *hp, *tp;
		}ptr;
	};
}*GList; 

/*
typedef struct GLNode{
    ElemTag tag;
    union{
        AtomType atom;
        struct GLNode *hp;    //�����б�hpָ���б��ڲ���һ��Ԫ�أ���tp��ָ�򱾲���ϵ���һ��Ԫ�� 
    };                        
    struct GLNode *tp;
} *GList;
*/
