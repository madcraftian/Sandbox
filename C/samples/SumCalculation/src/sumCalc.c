#include <stdio.h>
#include <stdlib.h>

int main(int arc, char* argv[])
{
	/* Sum Calculation */

	int input;
	printf("Enter the total count: ");
	scanf("%d", &input);

	const int maxCount = input;
	int sum = 0;

	for (int i = 1; i <= maxCount; i++)
	{
		sum += i;
	}

	printf("Sum: %d\n", sum);
	
	return EXIT_SUCCESS;
}
