#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 3
#define MAX_STRING 100

typedef struct {
	int num;
	char letter[MAX_STRING];
} element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init(StackType *s)
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}
// �����Լ�
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->stack[--(s->top)];
}
// ��ũ�Լ�
element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->stack[s->top];
}
// ���� ��� �Լ�
void stack_print(StackType *s) 
{
	if (is_empty(s))
		printf("<empty>\n");
	else
	{
		int i = s->top;
		printf("[%d, %s] <-- top\n", s->stack[i].num, s->stack[i].letter);
		for (i = s->top-1; i > -1; i--)
			printf("[%d, %s]\n", s->stack[i].num, s->stack[i].letter);
		printf("--\n");
			
	}
}
// ===== ���� �ڵ��� �� ===== 


int main(void)
{
	StackType s;
	element e;
	
	init(&s);
	stack_print(&s);
	
	e.num = 10;
	strcpy(e.letter, "ten");
	push(&s, e);
	stack_print(&s);
	
	e.num = 20;
	strcpy(e.letter, "twenty");
	push(&s, e);
	stack_print(&s);
	
	e.num = 30;
	strcpy(e.letter, "therty");
	push(&s, e);
	stack_print(&s);
	
	e.num = 40;
	strcpy(e.letter, "fourty");
	push(&s, e);
	stack_print(&s);
	
	pop(&s);
	stack_print(&s);
	
	e.num = 50;
	strcpy(e.letter, "fifty");
	push(&s, e);
	stack_print(&s);
	
	pop(&s);
	stack_print(&s);
	
	pop(&s);
	stack_print(&s);
	
	pop(&s);
	stack_print(&s);
}
