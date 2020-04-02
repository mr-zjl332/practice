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
	
	(*L) = (DuLinkedList)malloc(sizeof(DuLNode));  //创建头指针空间 
	(*L) -> prior = NULL;
	(*L) -> next = NULL;  //前后指针均指向空指针 
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
	//单向遍历整个列表，并逐一释放，最后将头指针指向空指针 
	DuLinkedList p, q;
	p = (*L) -> next;
	while(p)
	{
		q = p -> next;  //记录将被删除的节点的下一个节点 
		free(p);
		p = q;  //继续向后 
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
	
	DuLNode* s = p -> prior;  //找到p的前一个节点 
	q -> prior = s;  //将q插入s后 
	q -> next = p;   //将q插入p前 
	s -> next = q;   //使s连接q 
	p -> prior = q;  //使p连接q 
	
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
	
	DuLNode* s = p -> next;  //找到p的后一个节点
	q -> next = s;   //将q插入s前
	q -> prior = p;  //将q插入p后
	p -> next = q;   //使p连接q 
	s -> prior = q;  //使s连接q
	
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
	
	DuLNode* s = p -> next;  //找到p的下一个节点并储存为s 
	p -> next = s -> next;   //令p指向的下一个节点为s的下一节点 
	s -> next -> prior = p;  //令s节点的下一节点的prior指针指向p 
	*e = s -> data;          //将s节点的值取出并赋值给*e 
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


Status Createdulinklist(DuLinkedList *L)   //该函数用于创建链表 
{
	int n, i = 0;
 	printf("请输入n表示即将输入的数字个数(用以构建链表)：");
 	scanf("%d", &n);
 	printf("\n\n下面请输入%d个数(中间用空格隔开)：", n);
 	
 	DuLinkedList p, r;
 	r = *L;
 	for(i = 0; i < n; i++)  //尾插法建立链表 
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


Status Traverdulinklist(DuLinkedList *L)   //该函数用于遍历链表 
{
	int i = 1;
	DuLinkedList r;
	r = ((*L) -> next);
	printf("\n生成的链表结构为：%d", r->data);
	r = r -> next;
	while(r != NULL)  //遍历检查生成的节点 
	{
		printf(" -> %d", r -> data);
		i++; 
		r = r -> next;
	}
	printf("\n一共有%d个节点", i);
}
