#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;

typedef enum Status {
	ERROR,
	SUCCESS,
} Status;

int main() 
{
	DuLinkedList* h;
 	h = (DuLinkedList*)malloc(sizeof(DuLinkedList));
	InitList_DuL(h);
	
	Createdulinklist(h);   //该函数用于创建链表
	Traverdulinklist(h);   //该函数用于遍历链表 
	
	/*DuLNode* q;             //想插入q节点却实现不了，不知道是不是用法错了 
	q = (DuLinkedList)malloc(sizeof(DuLNode));
	q -> prior = NULL;
	q -> next = NULL;
	q -> data = 3333;
	InsertAfterList_DuL(q, ((*h)->next));*/

	/*DestroyList_DuL(h);*/   //销毁函数也实现不了，找了很久也没找到原因 

	return 0;
}
