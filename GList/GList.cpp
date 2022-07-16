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
        struct GLNode *hp;    //对于列表，hp指向本列表内部第一个元素，而tp是指向本层次上的下一个元素 
    };                        
    struct GLNode *tp;
} *GList;
*/
