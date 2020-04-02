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

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	
	(*L) = (DuLinkedList)malloc(sizeof(DuLNode));  //����ͷָ��ռ� 
	(*L) -> prior = NULL;
	(*L) -> next = NULL;  //ǰ��ָ���ָ���ָ�� 
	(*L) -> data = 0;
	
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	//������������б�����һ�ͷţ����ͷָ��ָ���ָ�� 
	DuLinkedList p, q;
	p = (*L) -> next;
	while(p)
	{
		q = p -> next;  //��¼����ɾ���Ľڵ����һ���ڵ� 
		free(p);
		p = q;  //������� 
	} 
	(*L) -> next = NULL;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	
	DuLNode* s = p -> prior;  //�ҵ�p��ǰһ���ڵ� 
	q -> prior = s;  //��q����s�� 
	q -> next = p;   //��q����pǰ 
	s -> next = q;   //ʹs����q 
	p -> prior = q;  //ʹp����q 
	
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	
	DuLNode* s = p -> next;  //�ҵ�p�ĺ�һ���ڵ�
	q -> next = s;   //��q����sǰ
	q -> prior = p;  //��q����p��
	p -> next = q;   //ʹp����q 
	s -> prior = q;  //ʹs����q
	
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	
	DuLNode* s = p -> next;  //�ҵ�p����һ���ڵ㲢����Ϊs 
	p -> next = s -> next;   //��pָ�����һ���ڵ�Ϊs����һ�ڵ� 
	s -> next -> prior = p;  //��s�ڵ����һ�ڵ��priorָ��ָ��p 
	*e = s -> data;          //��s�ڵ��ֵȡ������ֵ��*e 
	free(s);
	
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	
}


Status Createdulinklist(DuLinkedList *L)   //�ú������ڴ������� 
{
	int n, i = 0;
 	printf("������n��ʾ������������ָ���(���Թ�������)��");
 	scanf("%d", &n);
 	printf("\n\n����������%d����(�м��ÿո����)��", n);
 	
 	DuLinkedList p, r;
 	r = *L;
 	for(i = 0; i < n; i++)  //β�巨�������� 
 	{
        int a;
 		scanf("%d", &a);
 		p = (DuLinkedList)malloc(sizeof(DuLNode));
 		p -> data = a;
 		p -> prior = r;
 		r -> next = p;
 		p -> next = NULL;
		r = p; 
	}
}


Status Traverdulinklist(DuLinkedList *L)   //�ú������ڱ������� 
{
	int i = 1;
	DuLinkedList r;
	r = ((*L) -> next);
	printf("\n���ɵ�����ṹΪ��%d", r->data);
	r = r -> next;
	while(r != NULL)  //����������ɵĽڵ� 
	{
		printf(" -> %d", r -> data);
		i++; 
		r = r -> next;
	}
	printf("\nһ����%d���ڵ�", i);
}
