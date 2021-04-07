#include <stdio.h>
#include <stdlib.h>
// ���������а� 20170581 ��ȿ�� 
typedef int element;
typedef struct ListNode { 	// ��� Ÿ��
	element data;
	struct ListNode *link;
} ListNode;

// ���� ó�� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode*  insert_next(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)	
	pre->link = p;		//(4)	
	return head;		//(5)	

}

ListNode* insert_first(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// ��� �������� ���� ����	//(3)
	head = p;	// ��� ������ ����		//(4)

	return head;	// ����� ��� ������ ��ȯ
}

ListNode* insert_last(ListNode *head, int value)
{

	ListNode *temp = head;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;	
	p->link = NULL;
	// (2)
	if (head == NULL) // ���� ����Ʈ�̸�
		head = p;
	else {
		while (temp->link != 0) 
			temp = temp->link;

		temp->link = p;
	}


	return head;	//��� ������ ��ȯ
}
// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. 
ListNode* delete_next(ListNode *head, ListNode *pre) // pre�� ��Ȯ�� �ִٰ� ����(NULL�� �ƴϰ�)
{
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);			// (3)

	return head;			// (4)
}
void print_list(ListNode *head)
{
	ListNode *p;
	for (p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

ListNode *search(ListNode *head, int x)
{
	ListNode *p;
	p = head;
	while( p != NULL ){
		if( p->data == x ) return p;              // Ž�� ����
		p = p->link;
	}
	return NULL;  // Ž�� ������ ��� NULL ��ȯ



}
ListNode *concat(ListNode *head1, ListNode *head2)
{
	ListNode *p;
	if( head1 == NULL ) return head2;
	else if( head2 == NULL ) return head1;
	else {
		p = head1;             
		while( p->link != NULL ) 
			p = p->link;    
		p->link = head2;        
		return head1;           



	}
}
ListNode *reverse(ListNode *head)
{
   // ��ȸ �����ͷ� p, q, r�� ���
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

ListNode* delete_first(ListNode *head)
{
	ListNode *removed;
	if (head == NULL) error("������ �׸��� ����");
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)

}

ListNode* delete_last(ListNode *head)
{
	ListNode *temp = head;
	ListNode *prevTemp;
	ListNode *removed;
	if (head == NULL) error("������ �׸��� ����");
		if (temp->link == NULL) { // �ϳ��� ���
		removed = temp->link;
		free(removed);
		return NULL;
	}
	else { // �� �̻��� ���

		while (temp->link != NULL) {
			prevTemp = temp;
			temp = temp->link;
		}
		removed = temp;
		prevTemp->link = NULL;
		free(removed);
		return head; // �״��
	}
}
// item�� ����Ʈ�� ������ 1�� �ƴϸ� 0�� ��ȯ
int is_in_list(ListNode *head, element item)
{
	ListNode *p;
	p = head;
	while( p != NULL ){
		if( p->data == item ) return 1;  
		p = p->link;
	}
	return 0; 
}
int get_length(ListNode *head)
{
	int length = 0;
	while ( head != NULL )
	{
		head = head->link;
		length++;
	}
	return length;
}
int get_total(ListNode *head)
{
	int sum = 0;
	while ( head != NULL )
	{
		sum += head->data;
		head = head->link;
	}
	return sum;
}
element get_entry(ListNode *head, int pos)
{
	int i = 0;
	while ( i != pos )
	{
		head = head->link;
		i++;
	}
	return head->data;
}
ListNode * insert_pos(ListNode *head, int pos, element value)
{
	int i = 0;
	ListNode *preTemp = head;
	ListNode *temp = head;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)

	while ( i != pos - 1)
	{
		preTemp = temp;
		temp = temp->link;
		i++;
	}
	p->data = value;					// (2)
	p->link = temp->link;
	preTemp->link->link = p;

	return head;	
}
ListNode * delete_pos(ListNode *head, int pos)
{
	int i = 0;
	ListNode *temp = head;
	ListNode *prevTemp;
	ListNode *removed;
	if (head == NULL) error("������ �׸��� ����");
		if (temp->link == NULL) { // �ϳ��� ���
		removed = temp->link;
		free(removed);
		return NULL;
	}
	else { // �� �̻��� ���

		while ( i != pos)
		{
			prevTemp = temp;
			temp = temp->link;
			i++;
		}
		removed = temp;
		prevTemp->link = temp->link;
		free(removed);
		return head; // �״��
	}
}
int main(void)
{
	ListNode *list1 = NULL, *list2 = NULL, *list3;
	
	//list1 = 30->20->10->�� �����. �̶� 10, 20, 30�� ������ ��带 �����Ѵ�.
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);
	// list1�� ���
	printf("list1 = ");
	print_list(list1);

	//list1�� �� �� ��带 �����Ѵ� ��, list1 = 20->10->
	list1 = delete_first(list1);
	// list1�� ���
	print_list(list1);

	//list2 = 11->22->33->44->�� �����. �̶� 11, 22, 33, 44�� ������ ��带 �����Ѵ�.
	list2 = insert_last(list2, 11);
	list2 = insert_last(list2, 22);
	list2 = insert_last(list2, 33);
	list2 = insert_last(list2, 44);
	
	// list2�� ���
	print_list(list2);
	// list2�� �� �� ��带 �����Ѵ�. ��, list2 = 11->22->33->
	list2 = delete_last(list2);
	// list2�� ���
	print_list(list2);
	//list2�� �������� �ٲ� ����Ʈ�� list3�� ����Ű�� �Ѵ�. list3 = 33->22->11->�� �����.
	list3 = reverse(list2);
	//list3�� ����Ѵ�.  
	print_list(list3);
	// list1 = 20->10->33->22->11->�� �����. ��, list1�� list3�� ���ļ� list1�� ����Ű�� �Ѵ�.
	list1 = concat(list1, list3);
	//list1�� ����Ѵ�.
	print_list(list1);
	//(A) ����: ���⼭���ʹ� list1�� ����Ͽ� �Լ����� �׽�Ʈ����4
	// 20 Ž�� (�����Ƿ� 1 ���) 
	printf("%d\n", is_in_list(list1, 20));
	// 21 Ž�� (�����Ƿ� 0 ���) 
	printf("%d\n", is_in_list(list1, 21));
	// ����(5) ���
	printf("%d\n", get_length(list1)); 
	// ��(96) ��� 
 	printf("%d\n", get_total(list1));
 	// pos = 2 �� �� (33) ���
	printf("%d\n", get_entry(list1, 2)); 
	// pos = 2 ��ġ�� value 55 �߰� �� ��� 20->10->55->33->22->11->
	list1 = insert_pos(list1, 2, 55); 
	print_list(list1);
	// pos = 1 �� �� ���� �� ���  20->55->33->22->11->
	list1 = delete_pos(list1, 1); 
	print_list(list1);
}

