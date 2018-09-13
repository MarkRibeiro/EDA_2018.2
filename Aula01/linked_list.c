#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct node
{
    int val;
    struct node * next;
} Node;

int aleatorio(void)
{
  double r;
  r = (double) rand()/RAND_MAX;
  return (int)(0 + r*(31-0));
}

void iniciar_aleatorio(void)
{
  srand((unsigned int)time(NULL));
  rand(); rand(); rand();
}

void print (Node *list)
{
	Node* sweep = list;
	while(sweep!=NULL)
	{
		printf("%d-->", sweep->val);
		sweep=sweep->next;
	}
	
	printf("NULL\n");
}
Node* push (int x, Node *list)
{
	Node *head;
	head=(Node*)malloc(sizeof(Node));

	head->val=x;
	head->next=list;
	return head;
}

void pop (int x, Node *list)
{
	Node *trash;
 	while(list!=NULL)
 	{
 		if(list->val==x)
 		{
 		    free(list);
 		}
 		else
 			list=list->next;
 	} 
}

int main (void)
{
	Node *list;
	list = NULL;

	//iniciar_aleatorio();
		
	list = push(10, list);
	list = push(20, list);
	list = push(30, list);
	list = push(30, list);
    
    pop(20, list);
	print(list);

	return 0;

}
