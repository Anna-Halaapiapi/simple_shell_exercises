#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/**
 * main - prints "$ ", waits for user to enter command, prints it on next line.
 *
 * Return: 0
 */

int main(void)
{
	char *buffer = NULL; /* store input line from user */
	size_t buffsize = 0; /* store size of buffer */
	ssize_t numsread;/*store num of chars read by getline or -1(EOF/error)*/
    char **currenttokenarray; /* store token array from getline */
    int i; /* track array index position */

	while (1)
	{
		printf("$ "); /* print $ */
		fflush(stdout);/*flush to stdout in case $ is stored in buffer*/

		/* read line from stdin, store chars read*/
		numsread = getline(&buffer, &buffsize, stdin);
        currenttokenarray = splitstring(buffer); /* split buffer and store tokens */

		if (numsread == -1) /* check for getline failure or EOF */
		{
			printf("getline end\n");
			break;
		}
        i = 0; /* start print from beginning of array each time */
		while (currenttokenarray[i] != NULL)
        {
            printf("Token %d: %s\n", i, currenttokenarray[i]);
            i++;
        }
        free(currenttokenarray);
	}

	free(buffer); /* free line in buffer */

	return (0);
}
