#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int arc, char* argv[])
{
	/* SIMPLE STRING ENCRYPTION */
	const char* alphaChars   = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char* encryptChars = "qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGH";
	const int encryptCharLen = strlen(alphaChars);
	
	char input[128];
	printf("input: ");
	scanf("%126s", input);
	
	const size_t inputLen = strlen(input);
	char output[inputLen + 1];
	output[inputLen] = '\0';

	for (int i = 0; i <= inputLen - 1; i++)
	{
		for (int j = 0; j < encryptCharLen; j++)
		{
			if (input[i] == alphaChars[j])
			{
				output[i] = encryptChars[j];
				break;
			}
		}
	}

	printf("output: %s\n", output);
	return EXIT_SUCCESS;
}
