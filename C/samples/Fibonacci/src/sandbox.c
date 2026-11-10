#include <stdio.h>
#include <stdlib.h>

int main(int arc, char* argv[])
{
	// Number of fibonacci numbers to generate
	int count = 10;

	// Initialize the first two terms of the sequence
	int firstTerm = 0, secondTerm = 1;

	printf("First %d Fibonacci numbers\n", count);

	while (count > 0)
	{
		// PRint the current Fibonacci number
		printf("%d, ", firstTerm);

		int nextTerm = firstTerm + secondTerm; // Calculate the next Fibonacci number
		firstTerm = secondTerm;                // Update the first term with the value of the second term
		secondTerm = nextTerm;                 // Update the second term with the value of the next term
		count--;                               // Decrease the count of the next iteration
	}

	return EXIT_SUCCESS;
}
