#include <cstdlib>
#include <stdio.h>
#include <iostream>

typedef struct{
	int weight;
	int parent, left, right;
}HTNode, *HuffmanTree;


// 构建哈夫曼树
void CreatHuffmanTree(HuffmanTree *HT, int *w, int n){
	if(n <= 1){
		return;
	}
	
	int m = 2 * n -1; // 总结点数
	*HT = (HuffmanTree)malloc((m + 1) * sizeo(HTNode));
	HuffmanTree p = *HT;
	
	for(int i = 1; i <= n; i++){
		(p+i)->weight = *(w+i-1);
        (p+i)->parent = 0;
        (p+i)->left = 0;
        (p+i)->right = 0;
	} 
	for(int i = n+1; i <= m; i++) {
        (p+i)->weight = 0;
        (p+i)->parent = 0;
        (p+i)->left = 0;
        (p+i)->right = 0;
    }
    for(int i = n+1; i <= m; i++) {
        int s1, s2;
        Select(*HT, i-1, &s1, &s2);    //查找内容，需要用到查找算法
        (*HT)[s1].parent = (*HT)[s2].parent = i;
        (*HT)[i].left = s1;
        (*HT)[i].right = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
} 

//HT数组中存放的哈夫曼树，end表示HT数组中存放结点的最终位置，s1和s2传递的是HT数组中权重值最小的两个结点在数组中的位置
void Select(HuffmanTree HT, int end, int *s1, int *s2) {
    int min1, min2;
//遍历数组初始下标为 1
    int i = 1;
//找到还没构建树的结点
    while(HT[i].parent != 0 && i <= end) {
        i++;
    }
    min1 = HT[i].weight;
    *s1 = i;
    i++;
    while(HT[i].parent != 0 && i <= end) {
        i++;
    }
//对找到的两个结点比较大小，min2为大的，min1为小的
    if(HT[i].weight < min1) {
        min2 = min1;
        *s2 = *s1;
        min1 = HT[i].weight;
        *s1 = i;
    } else {
        min2 = HT[i].weight;
        *s2 = i;
    }
//两个结点和后续的所有未构建成树的结点做比较
    for(int j=i+1; j <= end; j++) {
//如果有父结点，直接跳过，进行下一个
        if(HT[j].parent != 0) {
            continue;
        }
//如果比最小的还小，将min2=min1，min1赋值新的结点的下标
        if(HT[j].weight < min1) {
            min2 = min1;
            min1 = HT[j].weight;
            *s2 = *s1;
            *s1 = j;
        }
//如果介于两者之间，min2赋值为新的结点的位置下标
        else if(HT[j].weight >= min1 && HT[j].weight < min2) {
            min2 = HT[j].weight;
            *s2 = j;
        }
    }
}































