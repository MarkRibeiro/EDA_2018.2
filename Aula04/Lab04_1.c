#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#define COUNT 10 
#define SIZE 32

typedef struct node 
{ 
    int data; 
    struct node* left, *right; 
}Node; 
   
Node* newNode(int data) 
{ 
    Node* node;
	node=(Node*)malloc(sizeof(Node));
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
}

struct node* insert(struct node* node, int data)
{
    if (node == NULL) return newNode(data);
 
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);   
 
    return node;
} 

void print2DUtil(Node *root, int space) 
{ 
    if (root == NULL) 
        return; 
  
    space += COUNT; 
  
    print2DUtil(root->right, space); 
  
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->data); 
  
    print2DUtil(root->left, space); 
} 
 
int main() 
{ 
    struct node *arv1 = NULL, *arv2 = NULL;

	srand(time(NULL));
	arv1 = insert(arv1, 10);
	insert(arv1, 20);
    insert(arv1, 5);
	printf("**********Arvore 1**********\n");
	print2DUtil(arv1, 0);
	printf("\n");

	arv2 = insert(arv2, 20);
	insert(arv2, 10);
    insert(arv2, 40); 
	printf("**********Arvore 2**********\n");
	print2DUtil(arv2, 0);
	printf("\n");
	
    return 0; 
} 

