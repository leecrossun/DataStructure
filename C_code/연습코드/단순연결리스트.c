#include <stdio.h>
#include <stdlib.h>
// �ܼ� ���� ����Ʈ 
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;
// ���� ó��
void error (char * message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
} 
// ��� ����
ListNode* insert_next (ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}
ListNode* insert_first (ListNode *head, element value)
{
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
ListNode* insert_last (ListNode *head, element value)
{
	ListNode *temp = head;
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;
	if (head == NULL)
		head = p;
	else
	{
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = p;
		return head;
	}
}
// ��� ����
ListNode* delete_next (ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link;
	pre->link = pre->link->link;
	free(removed);
	return head; 
}
ListNode* delete_first (ListNode *head)
{
	ListNode *removed;
	removed = head;
	head = head->link;
	free(removed);
	return head;
}
ListNode* delete_last (ListNode *head)
{
	ListNode *temp = head;
	ListNode *prevtemp;
	ListNode *removed;
	if (head == NULL) error("������ �׸��� ����");
	else
	{
		if ( head->link == NULL)
		{
			free(head);
			return NULL;
		}
		else
		{
			while (temp->link != NULL)
			{
				prevtemp = temp;
				temp = temp->link;
			}
			prevtemp->link = NULL;
			free(temp);
		}
		return head;
	 } 
}
// ���
void print_list (ListNode *head)
{
	ListNode *p;
	for (p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("\n");
}
// Ž��
ListNode *search (ListNode *head, int x)
{
	ListNode *p;
	p = head;
	while (p->data != x)
		p = p->link;
	return p;
}
ListNode *concat (ListNode *head1, ListNode *head2)
{
	ListNode *p;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else
	{
		ListNode *temp = head1;
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = head2;
		return head1;
	}
}
ListNode *reverse (ListNode *head)
{
	ListNode *p, *q, *r;
    p = head;         // p�� �������� ���� ����Ʈ
    q = NULL;         // q�� �������� ���� ���
    while (p != NULL){
       r = q;            // r�� �������� �� ����Ʈ.    r�� q, q�� p�� ���ʷ� ���󰣴�.
       q = p          ;
       p = p->link     ;
       q->link =r;      // q�� ��ũ ������ �ٲ۴�.
    }
    return q; 	// q�� �������� �� ����Ʈ�� ��� ������
}
int main(void)
{
	ListNode *head1 = NULL, *head2;
	int i;

	head1 = insert_last(head1, 10);
	print_list(head1);
	head1 = insert_last(head1, 20);
	print_list(head1);
	head1 = insert_last(head1, 30);
	print_list(head1);
	
	head2 = reverse(head1);
	print_list(head2);

	head2 = delete_last(head2);
	print_list(head2);

	head1 = NULL;
	head1 = insert_first(head1, 100);
	head1 = insert_first(head1, 200);
	print_list(head1);
	head1 = concat(head1, head2);
	print_list(head1);
	
	
	return;
}
