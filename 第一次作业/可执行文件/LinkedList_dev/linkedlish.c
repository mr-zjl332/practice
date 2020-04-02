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
	*L = (LinkedList)malloc(sizeof(LNode));  //新建头节点
	(*L) -> data = 0;
	(*L) -> next = NULL;  //将头节点指向空指针 
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
		q = p -> next;  //记录将被删除的节点的下一个节点 
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
	if(!p)  //如果p是头指针则直接接在p后 
	{
		p -> next = q;
	}
	else
	{
		s = p -> next;  //s暂存p的下一个节点 
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
	if(!(p -> next))  //如果是头节点则结束 
	{
		return ERROR;
	}
	LNode* s;
	LNode* q;
	q = p -> next;  //q暂存p的下一节点 
	s = q -> next;  //s暂存q的下一节点 
	*e = q -> data; //将即将释放的节点值存在*e中 
	free(q);        //释放q节点 
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
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {     //第二个参数不懂 
	/*LNode* p;
	p = L;
	while(p -> next && p -> data != )  //遍历寻找-- 
	{
		p = p -> next;
	}
	if(!p || p -> data != )  //若未查找到e-- 
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
	while(p -> next && p -> data != e)  //遍历寻找e
	{
		p = p -> next;
		return SUCCESS;
	}
	if(!p || p -> data != e)  //若未查找到e
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
	LNode* faster;  //快指针 
	LNode* slower;  //慢指针 
	
	if(L == NULL)  //先判断是否为空 
	{
		return ERROR;
	}
	while(faster != NULL && faster->next != NULL)
	{
		faster = faster->next->next;  //快指针走两步
		slower = slower->next;        //慢指针走一步
		if(faster == slower)  //若相遇则成环
		{
			return SUCCESS;
		}
	}
	printf("未成环"); 
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
	
	//同时操作要调序的奇偶节点以及他们后面的两个节点(一共操作4个节点)
	LinkedList odd, even, a, b = NULL;
	odd = (*L) -> next;  //奇数节点 
	even = odd -> next;//偶数节点 
	a = even -> next;  //暂存第3个节点 
	b = a -> next;     //暂存第4个节点 
	(*L) -> next = even;   //头节点指向第二个节点 
	
	while(a != NULL && b != NULL)
	{
		even -> next = odd;
		odd -> next = a;   //奇偶对调 
		odd = a;
		even = b;   //记录奇偶节点的odd、even更新为第3、第4节点 
		a = even -> next;
		b = a -> next;   //a、b继续向后移2位用以记录 
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



Status Createlinkedlist(LinkedList *L)   //该函数用于创建链表 
{
	int n, i = 0;
 	printf("请输入n表示即将输入的数字个数(用以构建链表)：");
 	scanf("%d", &n);
 	printf("\n下面请输入%d个数(中间用空格隔开)：", n);
	
 	LinkedList p, r;
 	r = *L;
 	for(i = 0; i < n; i++)  //尾插法 
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


Status Traverlist(LinkedList *L)   //该函数用于遍历链表 
{
	int i = 1;
	LinkedList r;
	r = ((*L) -> next);
	printf("\n链表结构为：%d", r->data);
	r = r -> next;
	while(r != NULL)  //遍历检查生成的节点 
	{
		printf(" -> %d", r -> data);
		i++; 
		r = r -> next;
	}
	printf("\n一共有%d个节点\n", i);
}

Status Traverlist2(LinkedList *L)   //该函数用于遍历反转后的链表 
{
	int i = 1;
	LinkedList r;
	r = *L;
	printf("\n该链表反转后的结构为：%d", r->data);
	r = r -> next;
	while(r != NULL)  //遍历检查生成的节点 
	{
		if(!(r->next)) 
		{
			break;
		}
		printf(" -> %d", r -> data);
		i++; 
		r = r -> next;
	}
	printf("\n一共有%d个节点", i);
}
