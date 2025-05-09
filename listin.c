#include <stdio.h>
#include <stdlib.h>
#include "func_in.c"

// individual task, number: 9

void main()
{
	nf head1 = NULL, head2 = NULL, head3 = NULL;
	printf("It's my individual task for linked lists, here we go again...\n\n");
	
	get_num(&head1);
	printf("\n");
	get_num(&head2);
	printf("\n");
	pr_num(head1);
	printf("\n\n");
	pr_num(head2);
	printf("\n\n");

	printf("So now we have 2 linked lists we should deal with.\n");
	printf("Now let's do our main task - search for same numbers in our lists \n\n");
	head3 = (nf)malloc(sizeof(num));
	nf head5 = head2;
	while (head1)
	{
		while (head2)
		{
			search_in (head1, head2, head3);
			head2=head2->flag;			
		}
		head1=head1->flag;
		head2=head5;
	}
	printf("\n");
	if(head3->flag == NULL)
		printf("There are no matching numbers in lists. \n");
	else
	{
		head3 = head3->flag;
		printf("Our list with same numbers will be: \n");
		pr_num(head3);
		printf("\n");
	}
}