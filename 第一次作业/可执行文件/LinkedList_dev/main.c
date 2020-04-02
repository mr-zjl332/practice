#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {
	ElemType data;
  	struct LNode *next;
} LNode, *LinkedList;

int main() 
{
 	LinkedList* h;
 	h = (LinkedList*)malloc(sizeof(LinkedList));
	InitList(h);  //创建包含头节点的列表 
	
	Createlinkedlist(h);  //调用函数 Createlinkedlist()构建链表 
	
	int e = 3;            //查找3是否存在于链表中 
	if(SearchList(*h, e))
	{
		printf("\n数值%d存在于链表中\n", e);
	}
	
	Traverlist(h);   //调用Traverlist函数遍历链表 
	
	/*ReverseEvenList(h);*/  //调了很久发现还是实现不了 
	
	ReverseList(h);  //调用函数 ReverseList()将链表反转 
	Traverlist2(h);  //用另一个遍历函数遍历新的链表 

	
	return 0;
}
