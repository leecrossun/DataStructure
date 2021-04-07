#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode *link;
} ListNode;

void print_list(ListNode* head) // Ʋ��(�����ؾ�)
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data); // ������ ��� ���
	printf("\n");
}

ListNode* insert_first(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
	}

	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
		head = node;		// (3)
	}
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}

ListNode* delete_first(ListNode* head)
{
     ListNode *temp;
     if (head == NULL) {
          printf("����Ʈ�� ��� ������ ����\n");
          return NULL;
     } 

     else if (head == head->link) {  // �� �ϳ��� ��尡 �������� 
          temp = head;
          head = NULL;
          free(temp);
     }
    else {
          temp = head->link;
          head->link = temp->link;
          free(temp);
     }
return head;

}

ListNode* delete_last(ListNode* head)
{
	ListNode *temp = head;
	ListNode *cur = head;
	
	if (head == NULL)
	{
		printf("����Ʈ�� ����־� ������ ����\n");
		return head; 
	}
	else
	{
		while (temp->link != head)
		{
			temp = temp->link;
		}
		temp->link->link = cur;
		head->link = temp->link;
		free(cur);
		return head;
	}	
}

ListNode* search(ListNode* head, element data)
{
	ListNode *temp = head;

	if (head == NULL)
		printf("ã�� ���� �����ϴ�.\n"); 
	else
	{
			while (temp->data != data)
			{
				temp = temp->link;
			}
			return temp;

	}
}

int get_size(ListNode* head)
{
	ListNode *temp = head;

	int size = 0;
	
	if (head == NULL)
		return 0;
	else
	{
		do
		{
			temp = temp->link;
			size++;
		} while (temp != head);
		return size;	
	}
}
// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)
{
	ListNode *head = NULL;

	// list = 10->20->30->40
	head = insert_last(head, 20);
	print_list(head);
	
	head = insert_last(head, 30);
	print_list(head);
	head = insert_last(head, 40);
	print_list(head);
	head = insert_first(head, 10);
	print_list(head);

	head = delete_first(head);
	print_list(head);
	
	delete_last(head);
	print_list(head);
	
	printf("%d\n", get_size(head));
	printf("%d\n", search(head,30)->data);
	

	return 0;
}

