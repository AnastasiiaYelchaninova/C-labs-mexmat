#include <stdio.h>
#include <malloc.h>
#include "str_in.h"

void get_num(nf* top)
{
	int c;
	printf("Enter number: ");
	scanf("%d", &c);
	if(c != 8)
	{
		*top = (nf)malloc(sizeof(num));
		(*top)->n = c;
		get_num(&((*top)->flag));
	}
	else
		*top=NULL;
}

void pr_num(nf top)
{	
	if (top) 
	{
		printf("%d", top->n);
		pr_num(top->flag);
	}
}

void add_in(nf r3, int d)
{
	nf r4 = (nf)malloc(sizeof(num));
	r4->n = d;
	r4->flag = NULL;
	while (r3->flag != NULL)
		r3 = r3->flag;
	r3->flag = r4;
}

int compare (nf r3, int m)
{
	int d;
	while(r3)
	{
		if(r3->n == m)
			return 0;
		else
			d = 1;
		r3=r3->flag;
	}
	return d;
}

void search_in (nf r1, nf r2, nf r3)
{
	int mark=0;
	if(r2->n==r1->n)
	{	
		mark = compare(r3, r1->n);
		if(mark)
		{
			printf("Found a match: %d \n", r1->n);
			add_in(r3, r1->n);
		}
	}
}
