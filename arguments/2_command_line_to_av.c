#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * splitstring - splits a string into indivual tokens/words
 * fullstring: the full line to split into tokens
 *
 * Return: array of pointers to tokens
 */

char **splitstring(char *fullstring)
{
	char **tokenarray; /* array to hold tokens */
	char *currenttoken; /* track current token to store in array */
	int index = 0; /* track index position in array */

	/* malloc array for 20 tokens */
	tokenarray = malloc(sizeof(char *) * 20);
	if (tokenarray == NULL) /* check for malloc failure */
	{
		/* print error message */
		printf("malloc failure - program exited\n");
		exit(EXIT_FAILURE); /* exit program */
	}

	/* split tokens from fullstring and store each token in tokenarray */
	currenttoken = strtok(fullstring, " ");

	while (currenttoken != NULL)
	{
		tokenarray[index] = currenttoken;
		index++;
		currenttoken = strtok(NULL, " ");
	}

	/* add NULL to end of array */
	tokenarray[index] = NULL;

	return (tokenarray);
}
