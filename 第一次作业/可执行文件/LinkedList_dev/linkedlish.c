#include <stdlib.h>
typedef int ElemType;

 typedef struct LNode {
	ElemType data;
  	struct LNode *next;
} LNode, *LinkedList;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	*L = (LinkedList)malloc(sizeof(LNode));  //�½�ͷ�ڵ�
	(*L) -> data = 0;
	(*L) -> next = NULL;  //��ͷ�ڵ�ָ���ָ�� 
	return SUCCESS; 
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p, q;
	p = (*L) -> next;
	while(p)
	{
		q = p -> next;  //��¼����ɾ���Ľڵ����һ���ڵ� 
		free(p);
		p = q;
	} 
	(*L) -> next = NULL;
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	LNode* s;
	if(!p)  //���p��ͷָ����ֱ�ӽ���p�� 
	{
		p -> next = q;
	}
	else
	{
		s = p -> next;  //s�ݴ�p����һ���ڵ� 
		p -> next = q;
		q -> next = s;
	}
	
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	if(!(p -> next))  //�����ͷ�ڵ������ 
	{
		return ERROR;
	}
	LNode* s;
	LNode* q;
	q = p -> next;  //q�ݴ�p����һ�ڵ� 
	s = q -> next;  //s�ݴ�q����һ�ڵ� 
	*e = q -> data; //�������ͷŵĽڵ�ֵ����*e�� 
	free(q);        //�ͷ�q�ڵ� 
	p -> next = s;
	
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {     //�ڶ����������� 
	/*LNode* p;
	p = L;
	while(p -> next && p -> data != )  //����Ѱ��-- 
	{
		p = p -> next;
	}
	if(!p || p -> data != )  //��δ���ҵ�e-- 
	{
		return ERROR;
	}
	*/
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LNode* p;
	p = L;
	while(p -> next && p -> data != e)  //����Ѱ��e
	{
		p = p -> next;
		return SUCCESS;
	}
	if(!p || p -> data != e)  //��δ���ҵ�e
	{
		return ERROR;
	}
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	
	
	LNode* cur = NULL;
	LNode* pre = *L;
	while(pre != NULL)
	{
		LNode* s = pre ->next;
		pre -> next = cur;
		cur = pre;
		pre = s;
	}
	(*L) = cur;

	return SUCCESS;
	
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LNode* faster;  //��ָ�� 
	LNode* slower;  //��ָ�� 
	
	if(L == NULL)  //���ж��Ƿ�Ϊ�� 
	{
		return ERROR;
	}
	while(faster != NULL && faster->next != NULL)
	{
		faster = faster->next->next;  //��ָ��������
		slower = slower->next;        //��ָ����һ��
		if(faster == slower)  //��������ɻ�
		{
			return SUCCESS;
		}
	}
	printf("δ�ɻ�"); 
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	
	//ͬʱ����Ҫ�������ż�ڵ��Լ����Ǻ���������ڵ�(һ������4���ڵ�)
	LinkedList odd, even, a, b = NULL;
	odd = (*L) -> next;  //�����ڵ� 
	even = odd -> next;//ż���ڵ� 
	a = even -> next;  //�ݴ��3���ڵ� 
	b = a -> next;     //�ݴ��4���ڵ� 
	(*L) -> next = even;   //ͷ�ڵ�ָ��ڶ����ڵ� 
	
	while(a != NULL && b != NULL)
	{
		even -> next = odd;
		odd -> next = a;   //��ż�Ե� 
		odd = a;
		even = b;   //��¼��ż�ڵ��odd��even����Ϊ��3����4�ڵ� 
		a = even -> next;
		b = a -> next;   //a��b���������2λ���Լ�¼ 
	}
	
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	
}



Status Createlinkedlist(LinkedList *L)   //�ú������ڴ������� 
{
	int n, i = 0;
 	printf("������n��ʾ������������ָ���(���Թ�������)��");
 	scanf("%d", &n);
 	printf("\n����������%d����(�м��ÿո����)��", n);
	
 	LinkedList p, r;
 	r = *L;
 	for(i = 0; i < n; i++)  //β�巨 
 	{
        int a;
 		scanf("%d", &a);
 		p = (LinkedList)malloc(sizeof(LNode));
 		p -> data = a;
 		r -> next = p;
 		p -> next = NULL;
		r = p; 
	}
	return SUCCESS;
}


Status Traverlist(LinkedList *L)   //�ú������ڱ������� 
{
	int i = 1;
	LinkedList r;
	r = ((*L) -> next);
	printf("\n����ṹΪ��%d", r->data);
	r = r -> next;
	while(r != NULL)  //����������ɵĽڵ� 
	{
		printf(" -> %d", r -> data);
		i++; 
		r = r -> next;
	}
	printf("\nһ����%d���ڵ�\n", i);
}

Status Traverlist2(LinkedList *L)   //�ú������ڱ�����ת������� 
{
	int i = 1;
	LinkedList r;
	r = *L;
	printf("\n������ת��ĽṹΪ��%d", r->data);
	r = r -> next;
	while(r != NULL)  //����������ɵĽڵ� 
	{
		if(!(r->next)) 
		{
			break;
		}
		printf(" -> %d", r -> data);
		i++; 
		r = r -> next;
	}
	printf("\nһ����%d���ڵ�", i);
}
