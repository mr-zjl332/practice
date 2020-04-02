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
	InitList(h);  //��������ͷ�ڵ���б� 
	
	Createlinkedlist(h);  //���ú��� Createlinkedlist()�������� 
	
	int e = 3;            //����3�Ƿ������������ 
	if(SearchList(*h, e))
	{
		printf("\n��ֵ%d������������\n", e);
	}
	
	Traverlist(h);   //����Traverlist������������ 
	
	/*ReverseEvenList(h);*/  //���˺ܾ÷��ֻ���ʵ�ֲ��� 
	
	ReverseList(h);  //���ú��� ReverseList()������ת 
	Traverlist2(h);  //����һ���������������µ����� 

	
	return 0;
}
