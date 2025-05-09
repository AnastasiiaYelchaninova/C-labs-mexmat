#include <stdio.h>
#include <stdlib.h>
#include "func_num1.c"

void main()
{
	nf head = NULL;
	int z, l;
	printf("Hi! It's a programm testing my 'deal-with-linked-list' skills.\n");
	printf("IDK where I will or not use it again, so let's begin with creating list :)\n\n");
	
	get_num(&head); //create a list
	printf("\n");
	pr_num(head); //display the result
	printf("\n\n");
	l = count_list(head); //count the number of items in the list (will be needed almost everywhere)
	printf("Number of nodes: %d \n\n", l);
	
	printf("CHOOSE YOUR DESTINY: \n");
	printf("2 - add numbers after specific numbers\n");
	printf("3 - add numbers on specific position\n");
	printf("4 - delete numbers on specific position\n");
	printf("5 - delete specific numbers\n");
	printf("0 - quit program\n\n");
	printf("Let's do this: ");
	scanf("%d", &z);
	printf("\n");

	while (z)
	{	
		switch(z)
	{			
		case 2 :	while(z==2)
				{
					int f;
					printf("Set a number you what to print smth after: ");
					scanf("%d", &f);
					printf("\n");
					l = ins_num(head, f, l); //we can return the number of elements if there are no other return values
					printf("\n");
					pr_num(head);			
	      				printf("\n\n");
					printf("If you want to make another changes - enter 2, quit - anything else: ");
					scanf("%d", &z);
				}			
				printf("\n");
				pr_num(head);
				printf("\n\n");
				break;
	
		case 3 :	while(z==3)
				{
					printf("Number of nodes: %d \n", l);
					int i;					
					printf("Set a number of place where you want to place element: ");
					scanf("%d", &i);
					if (i>l+1) //if the index is further than the place after the end of the list - there is no sense to go into the function, we do the rest of the checks in the function
						printf("INDEX OUT OF LIST - try again\n\n");
					else
        				{
							int k;
							printf("Set a value of new member: ");
							scanf("%d", &k);
							head = ins_place_num(head, k, i);
							l = count_list(head); //and here there is a return value, so we change it with a separate line
							printf("\n");
							pr_num(head);
							printf("\n\n");
							printf("If you want to make another changes - enter 3, quit - anything else: ");
							scanf("%d", &z);
					}				
				}
				printf("\n");
				pr_num(head);
				printf("\n\n");
				break;
	
		case 4 :	while(z==4)
				{
					printf("Number of nodes: %d \n", l);
					int i;
					printf("Set an index of element you want to delete: ");
					scanf("%d", &i);
					if (i>l) //if the index is outside the list - there is no point in going into the function, we do the rest of the checks in the function
						printf("INDEX OUT OF LIST - try again \n\n");
					else
        				{
							head = del_num(head, i);
							l = count_list(head); //and here there is a return value, so we change it with a separate line
							printf("\n");
							pr_num(head);
							printf("\n\n");
							printf("If you want to make another changes - enter 4, quit - anything else: ");
				        		scanf("%d", &z);
					}
				}
				printf("\n");
				pr_num(head);
				printf("\n\n");
				break;

		case 5 :	while(z==5)
				{
					int i, a;
					printf("Set a value of element you want to delete: ");
					scanf("%d", &i);
					if(head->n == i) //if the value we want to delete is in the root, then we replace the root at once
							 //If we need to get rid of a value that is both at the root and at other places in the list, we just run case 5 again using del_num_all
					{
						printf("This value is first ~deleting~");
						head = del_num(head, i);
						l--;
						printf("\n");
						pr_num(head);
                                                printf("\n\n");
						printf("If you want to make another changes - enter 5, quit - anything else: ");
						scanf("%d", &z);
					}
					else
					{
						printf("If you want to delete ALL elements with this value - enter 1, only first - anything else: ");
						scanf("%d", &a);
						if(a!=1) //removal of 1 element, similar to local removal
						{
							l = del_value_num(head, i, l);
							printf("\n");
							pr_num(head);
							printf("\n\n");
							printf("If you want to make another changes - enter 5, quit - anything else: ");
							scanf("%d", &z);
						}
						else
						{
							l = del_value_all(head, i, l);
							printf("\n");
							pr_num(head);
							printf("\n\n");
							printf("If you want to make another changes - enter 5, quit - anything else: ");
							scanf("%d", &z);
						}
					}				
				}
				printf("\n");
				pr_num(head);
				printf("\n\n");
				break;

		default:	printf("INCORRECT INPUT - please restart the programm\n\n");

	}
	printf("Let's try something else (to QUIT print 0) \n");
	printf("~REMAINDER~\n");
	printf("2 - add numbers after specific numbers\n");
	printf("3 - add numbers on specific position\n");
        printf("4 - delete numbers on specific position\n");
	printf("5 - delete specific numbers\n\n");
	scanf("%d", &z);
	}
	printf("\n");
	pr_num(head);
	printf("\n");
}