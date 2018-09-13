#include<stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct node
{
    int val;
	int ind;
    struct node * next;
	struct node * prev;
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
		printf("|I:%2d|V:%2d|\t", sweep->ind, sweep->val);
		sweep=sweep->next;
	}
	printf("\n\n");	
}

Node* push (int x, Node *list, int i)
{
	Node *first;
	first=(Node*)malloc(sizeof(Node));;

	first->val=x;
	first->ind=i;
	first->next=list;
	first->prev=NULL;	

	if(list!=NULL)
		list->prev=first;

	return first;
}

Node* pop (int n, Node *list)
{
	Node *trash = list;
	while(trash!=NULL && trash->val != n)
	{ 
		
		trash=trash->next;
	}
 	
	if(trash==NULL)
 		return list;
	if (trash->prev==NULL)
		list = trash->next;
 	else
		trash->prev->next = trash->next;
		trash->next->prev = trash->prev;
	free(trash);

	return list;
}

int search_count (Node *list, int n)
{
	Node* sweep = list;
	int aux=0;	
	
	while(sweep!=NULL)
	{
		if(sweep->val==n)
		{
			aux++;
		}
		sweep=sweep->next;
	}
	printf("O numero %d aparece %d vezes\n\n", n,aux);

	return n;
}

int main (void)
{
	Node *list;
	int i, n, aux;

	iniciar_aleatorio();	
	n=aleatorio();
	
	list = NULL;
	
	for(i=0;i<32;i++)
		list = push(aleatorio(),list, i);
    
	aux=search_count (list, n);

	i=0;
	print(list);
	while(i<aux)
	{
		list = pop(n, list);
		i++;
	}
	printf("Numero que sera apagado: %d\n\n", n);	
	print(list);

	return 0;
}
