#include <stdio.h>
#include <malloc.h>
#include "str_num1.h"

void get_num(nf* top) //create list
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

void pr_num(nf top) //output of a list on a screen
{	
	if (top) 
	{
		printf("%d / ", top->n);
		pr_num(top->flag);
	}
}

int count_list (nf top) //list item count
{
	int l = 0;
	while (top)
	{
		l++;
		top=top->flag;
	}
	if(l)
		return l++;
	else
		return l;
}

int ins_num(nf top, int f, int l) //inserting an element after the element with the specified info part
{
	nf new;
	int mark=0;
	while (top)
	{
		if(top->n==f)
		{
			new = (nf)malloc(sizeof(num));
			printf("Set number you want to be added: ");
			scanf("%d", &new->n);
			new->flag=top->flag;
			top->flag=new;
			top=top->flag;
			l++;
			printf("If you want to quit current task - enter 1, continue - anything else: ");
			scanf("%d", &mark);
			if(mark == 1)
				break;
		}
		else
		{
			top=top->flag;
			mark++; //will be needed three lines down
		}
	}
	if(mark == l) //went through the list and didn't find a value
		printf("We don't have such number in our list.");
	return l;
}

nf ins_place_num(nf top, int k, int i) //inserting an item to a specific position in the list
{
	if(i==1) //make a new root
	{
		nf cur = (nf)malloc(sizeof(num));
		cur->n = k;
		cur->flag = top;
		return 	cur;					
	}
	else //inserting an item somewhere inside / at the end of the list
	{
		nf t = top;
		for (int j=0; j<(i-2); j++)
			top=top->flag;
		nf cur = (nf)malloc(sizeof(num));
		cur->n = k;
		cur->flag = top->flag;
		top->flag = cur;
		return t;
	}
}

nf del_num(nf top, int i)
{
	if (i==1)
	{
		nf d = NULL;
		d = top->flag;
		free(top);
		top = d;
		return top;
	}
	else
	{	
		nf d = NULL, t = top;
		for (int j=0; j<(i-2); j++)
			top=top->flag;
		d = top->flag;
		top->flag = top->flag->flag;
		free(d);
		return t;
	}
}

int del_value_num(nf top, int i, int l)
{
	nf d = NULL;
	while(top->flag->n != i)						 
		top=top->flag;
	d = top->flag;
	top->flag = top->flag->flag;
	free(d);
	l--;
	return l;
}

int del_value_all(nf top, int i, int l)
{
	nf d = NULL, t = top;
	while(top->flag)
	{
		if(top->flag->n==i)
		{
			d = top->flag;
			top->flag = top->flag->flag;
			free(d);
		}
		else
			top=top->flag;
	}
	top = t;
	l = count_list(top);
	return l;
}
