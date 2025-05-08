//create a recursive function that finds the value of a degree with a given base
//(base is a real number, exponent is an integer)

#include <stdio.h>

// using more optimal degree formula:
// if an index is odd, the degree is considered as a product;
// if an index is even, the degree is considered as a smaller number squared;
// it is also considered if an index is negative;

float power(float base, int index) // calculate given number in given degree
{
	if (index == 0) return 1;
	if (index == 1) return base;
	if (index < 0) return power(1/base, -index);
	if (index % 2) return base*power(base, index-1);
	return power (base*base, index/2);
}

int main()
{	
	int index=1;
	float base;
	while (index)
	{	
		printf("Enter base and index: ");
		scanf("%f %d", &base, &index);
		printf("%f^%d = %f", base, index, power(base, index));
		printf("\nTo quit - enter 0, to continue - anything else: ");
		scanf("%d", &index);
		printf("\n");
	}
}
