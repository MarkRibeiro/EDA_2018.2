#include<stdio.h>
#include<stdlib.h>
#include <time.h>
typedef struct tree 
{
  int data;
  struct tree *left;
  struct tree *right;
}Tree;
//Cria no na arvore
Tree* create_node (int c) 
{
	Tree *r = (Tree*) malloc(sizeof(Tree));

	r->data = c;
	r->left =  r->right = NULL;

	return r;
}
//insere no na arvore
Tree* insert_node (Tree* r, int c)
{
	if (r==NULL) 
		return create_node(c);

	else if (c < r->data)
		r->left = insert_node(r->left, c);
	
	else  /* if (c > r->chave) */ 
		r->right = insert_node(r->right,c);
	
	return r;
}
//Gera numero aleatorio
int aleatorio(void)
{
	double r;
	r = (double) rand()/RAND_MAX;
	return (int)(0 + r*(100-0));
}
//Inicia contagem para numero aleatorio
void iniciar_aleatorio(void)
{
	srand((unsigned int)time(NULL));
	rand(); rand(); rand();
}
//Quicksort
void Quick(int *v, int inicio, int fim)
{
	int pivo, aux, i, j, meio;
   
	i = inicio;
	j = fim;
   
	meio = (int) ((i + j) / 2);
	pivo = v[meio];
   
	do
	{
		while (v[i] < pivo) i = i + 1;
		while (v[j] > pivo) j = j - 1;
      
		if(i <= j)
		{
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i = i + 1;
			j = j - 1;
		}
   }
	while(j > i);
   
	if(inicio < j) Quick(v, inicio, j);
	if(i < fim) Quick(v, i, fim);   
}
//Cria Vetor
int* constroi_vetor (void)
{
	int *v, i;

	v=(int *)malloc(32*sizeof(int));
	if(v==NULL)
	{
		exit (1);
	}

	for(i=0;i<32;i++)
		v[i]=aleatorio();

	v[i]='\0';
	return v;
}
int main ()
{
	int *n, i;
	
	iniciar_aleatorio();
	n=constroi_vetor();

	printf("Vetor desordenado\n");
	for(i=0;i<32;i++)
		printf("v[%d]=%d\n", i, n[i]);


	Quick(n, 0, 31);

	printf("Vetor ordenado\n");
	for(i=0;i<32;i++)
		printf("v[%d]=%d\n", i, n[i]);

	return 0;
}
