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
	
	Createdulinklist(h);   //�ú������ڴ�������
	Traverdulinklist(h);   //�ú������ڱ������� 
	
	/*DuLNode* q;             //�����q�ڵ�ȴʵ�ֲ��ˣ���֪���ǲ����÷����� 
	q = (DuLinkedList)malloc(sizeof(DuLNode));
	q -> prior = NULL;
	q -> next = NULL;
	q -> data = 3333;
	InsertAfterList_DuL(q, ((*h)->next));*/

	/*DestroyList_DuL(h);*/   //���ٺ���Ҳʵ�ֲ��ˣ����˺ܾ�Ҳû�ҵ�ԭ�� 

	return 0;
}
