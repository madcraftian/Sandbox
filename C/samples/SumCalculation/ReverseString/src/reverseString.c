#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF_SIZE 256

int main(int arc, char* argv[])
{
	/* REVERSING A STRING */

	char input[MAX_BUFF_SIZE];

	printf("input: ");
	scanf("%254s", input);
	
	char tmp[MAX_BUFF_SIZE];
	char out[MAX_BUFF_SIZE];
	strncpy(tmp, input, 256);

	for (int i = 0, j = strlen(tmp);
			j > 0; i++, j--)
	{
		out[i] = tmp[j - 1];
	}

	printf("output: %s", out);
	return EXIT_SUCCESS;
}
