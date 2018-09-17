#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 11

typedef struct tree
{
	int key;
	struct tree *left;
	struct tree *right;
}Tree;

void imprime_vetor(int *v)
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		printf("%d ", v[i]);
	}
}

void ini_random(void)
{
	srand((unsigned int)time(NULL));
	rand();
	rand();
	rand();
}

void create_vector(int *v)
{
	int i, j;

	for(i=0;i<SIZE;i++)
	{	
		JUMP:
		v[i]=rand() %100;
		for(j=0;j<i;j++)
		{
			if(v[j]==v[i])
				goto JUMP;
		}	
	}
}

int comp (const void * a, const void * b)
{
	int x = *(int *)a;
	int z = *(int *)b;

	return x-z;
}

Tree* create_tree(int n)
{
	Tree* new_tree = (Tree*) malloc(sizeof(Tree));
	if(new_tree==NULL)
	{
		printf("Sem memoria\n");
		exit(1);
	}

	new_tree->key=n;
	new_tree->left=NULL;
	new_tree->right=NULL;

	return new_tree;
}

Tree* insert_tree (Tree *t, int n)
{
	if(t==NULL)
	{
		t=create_tree(n);
		return t;
	}
	if(t->key>n)
		t->left=insert_tree(t->left, n);

	else
		t->right=insert_tree(t->right, n);
	
	return t;
}

Tree* balanced_BST(int star, int end, Tree *t, int *v)
{
    int midle = (star+end)/2;

    if(star >= end)
	{
        t = insert_tree(t, v[midle]);
        return t;
    }

    t = insert_tree(t, v[midle]);
    t = balanced_BST(star, midle-1, t, v);
    t = balanced_BST(midle+1, end, t, v);

    return t;
}

void print_BST(Tree *t)
{
	if(t!=NULL)
	{
		print_BST(t->left);
		printf("%d ", t->key);
		print_BST(t->right);
	}
}

int main (void)
{
	int v1[SIZE], v2[SIZE];
	Tree *t1=NULL, *t2=NULL;

	ini_random();

	create_vector(v1);
	create_vector(v2);

	qsort(v1, SIZE, sizeof(int), comp);
	qsort(v2, SIZE, sizeof(int), comp);

	t1 = balanced_BST(0, SIZE-1, t1, v1);
	t2 = balanced_BST(0, SIZE-1, t2, v2);


	print_BST(t1);
	printf("\n");

	imprime_vetor(v1);
	printf("\n");

	print_BST(t2);
	printf("\n");

	imprime_vetor(v2);
	printf("\n");

	return 0;
}
