#include <stdio.h>
typedef struct ListNode{
	int number;
	struct ListNode *link;
} ListNode;

int main(void)
{
	ListNode *head, *newNode, *temp;
	
	//1)
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 10;
	newNode->link = NULL;
	head = newNode;
	
	//2)
	newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->number = 20;
	newNode->link = NULL;
	head->link = newNode;
	
	//3)
	newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->number = 30;
	newNode->link = NULL;
	head->link->link = newNode;
	
	//4)
	newNode = (ListNode *)malloc(sizeof(ListNode));
	newNode->number = 10;
	newNode->link = NULL;
	//temp�� ������ ������ ����
	temp = head;
	while(temp->link != NULL)
		temp = temp->link;
	temp->link = newNode; 
	head->link = newNode;
	//5)
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number - 1;
	newNode->link = NULL;
	newNode->link = head;
	head = newNode;
	
	//6)7) displayList1, displayList2�� �ϼ��� �� ȣ��
	displayList1(head);
	printf("\n");
	displayList2(head); 
	
	return;
}
void displayList1(ListNode *head)
{
	ListNode *temp = head;
	while(temp->link != NULL)
	{
		printf("%d", temp->number);
		temp = temp->link;
	}
}
