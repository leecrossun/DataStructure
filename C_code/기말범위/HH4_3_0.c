// HW4_3
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAX_STRING 100

typedef struct {
     int id;
     char name[MAX_STRING];
	 char tel[MAX_STRING];
	 char dept[MAX_STRING];
} element;
typedef struct TreeNode {
	element data;
	struct TreeNode *left, *right;
} TreeNode;

TreeNode * search(TreeNode * node, int key)  // ���� ���ľ�
{	// �ڵ�   
	if (node == NULL) return NULL;
	if (key == node->data.id) return node;
	else if (key < node->data.id)
		return search(node->left, key);
	else
		return search(node->right, key);
}

TreeNode * new_node(element data)  // ���� ���ľ�
{	// �ڵ�   
	TreeNode * temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode * min_value_node(TreeNode * node) // �״��
{
	TreeNode * current = node;

	// �� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;

	return current;
}
 
TreeNode * delete_node(TreeNode * node, int key) // ���� ���ľ�
{	// �ڵ�  
	if (node == NULL) return node;
	
	if (key < node->data.id) node->left = delete_node(node->left, key);
	else if (key > node->data.id) node->right = delete_node(node->right, key);
	else
	{
		if (node->left == NULL)
		{
			TreeNode *temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL)
		{
			TreeNode *temp = node->left;
			free(node);
			return temp;
		}
		else
		{
			TreeNode *temp = min_value_node(node->right);
			node->data.id = temp->data.id;
			node->right = delete_node(node->right, temp->data.id);
		}
	}
	return node;
}

//�� �л� ���� ���
void print_data(element * e)
{
     printf("-----------------------------------\n");
     printf("�й�: %d\n", e->id);
     printf("�̸�: %s\n", e->name);
	 printf("��ȭ��ȣ: %s\n", e->tel);
	 printf("�а�: %s\n", e->dept);
}
TreeNode * insert_node(TreeNode * node, element data) // ���� ���ľ�
{	// �ڵ�    
	if (node == NULL) return new_node(data);
	if (data.id < node->data.id)
		node->left = insert_node(node->left, data);
	else if (data.id > node->data.id)
		node->right = insert_node(node->right, data);
}

// ���� ��ȸ
void inorder(TreeNode * root)  // ���� ���ľ�
{	// �ڵ�     
	if (root)
	{
		inorder (root->left);
		printf("[%d] ", root->data.id);
		inorder(root->right);
	}
}

int get_node_count(TreeNode *node)
{
     int count = 0;
     if (node != NULL)
          count = 1 + get_node_count(node->left) + get_node_count(node->right);
     return count;
}
int main(void)
{
     TreeNode *root = NULL;
     TreeNode *node;
     element data;
     char choice;
     int id;
     char name[MAX_STRING];
     char tel[MAX_STRING];
	 char dept[MAX_STRING];

     printf("Enter i(nsert), d(elete), s(earch), p(rint), c(ount), q(uit):");
     scanf("%c", &choice);
     while (choice != 'q') {
          switch (choice) {
          case 'i':
               printf("�й� �Է�:");
               scanf("%d", &id);
               printf("�̸� �Է�:");
               scanf("%s", name);;
			   printf("��ȭ��ȣ �Է�:");
               scanf("%s", tel);;
			   printf("�а� �Է�:");
               scanf("%s", dept);;

               data.id = id;
               strcpy(data.name, name);
               strcpy(data.tel, tel);
               strcpy(data.dept, dept);

               root = insert_node(root, data);
               break;
          case 'p':
               printf("�л� ���� �й� �� ���\n");
               inorder(root);
               printf("\n");
               break;
          case 'd':
               printf("������ �й� �Է�:");
               scanf("%d", &id);
               delete_node(root, id);
               break;
          case 's':  
               printf("Ž���� �й� �Է�:");
               scanf("%d", &id);

               node = search(root, id);
               if (node != NULL)
                    print_data(&(node->data));
               else
                    printf("id�� %d�� �л��� �����ϴ�.\n", id);
               break;
          
          case 'c':
               printf("���� ����� �л��� �� ���� %d\n", get_node_count(root));
               break;
          }

          while (getchar() != '\n'); // ���� ���
          printf("Enter i(nsert), d(elete), s(earch), p(rint), c(ount), q(uit):");
          scanf("%c", &choice);
     	}
          
     }     

