#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_STRING 100
#define MAX_STACK_SIZE 100

typedef char element; // ����: char���� ���ڸ� ���ÿ� �ִ´�
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
	return (s->top == (MAX_STACK_SIZE-1));
}
// �����Լ�
void push(StackType *s, element item)
{ 
  	  if( is_full(s) ) { 
		fprintf(stderr,"���� ��ȭ ����\n");
		return; 		 
	  } 
	  else s->stack[++(s->top)] = item; 
}
// �����Լ�
element pop(StackType *s) 
{ 
   	if( is_empty(s) ) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1); 		
	}
	else return s->stack[(s->top)--]; 
} 
// ��ũ�Լ�
element peek(StackType *s) 
{ 
   	if( is_empty(s) ) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1); 		
	}
	else return s->stack[s->top]; 
}

int palindrome(char str[])
{
	StackType s; 
	int i;
	char ch, chFromStack;
	int len = strlen(str);

     // ������ �ʱ�ȭ�϶�
	init(&s);

	//str�� ���ڵ��� ���ÿ� �ִ´�
	for(i = 0; i < len; i++)
		push(&s, str[i]);


    //���ÿ��� �ϳ��� ���鼭 str�� ���ڵ�� ���ʷ� �� 
	for(i = 0; i < len; i++)
	{
		ch = str[i];
		chFromStack = pop(&s);
		if(ch != chFromStack)
			break;
	}
	if(i == len)
		return 1;
	else
		return 0;



}

int main(void)
{
	char word[MAX_STRING];

	printf("Enter a word to check palindrome: ");
	scanf("%s", word);

	if (palindrome(word))
		printf("palindrome�Դϴ�.\n");
	else
		printf("palindrome�� �ƴմϴ�.\n");
}
