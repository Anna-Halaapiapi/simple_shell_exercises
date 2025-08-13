#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

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

	/* malloc array for 200 tokens */
	tokenarray = malloc(sizeof(char *) * 200);
	if (tokenarray == NULL) /* check for malloc failure */
	{
		/* print error message */
		printf("malloc failure - program exited\n");
		exit(EXIT_FAILURE); /* exit program */
	}

	/* split tokens from fullstring and store each token in tokenarray */
	currenttoken = strtok(fullstring, ":");

	while (currenttoken != NULL)
	{
		tokenarray[index] = currenttoken;
		index++;
		currenttoken = strtok(NULL, ":");
	}

	/* add NULL to end of array */
	tokenarray[index] = NULL;

	return (tokenarray);
}

/**
 * print_dir - prints each directory in PATH
 * 
 * Return: 0 (success) or 1 (fail)
 */

int main(void)
{
  int i = 0; /* loop counter */
  char **path_array; /* store PATH array */
  char *envpath = getenv("PATH"); /* get values of PATH */

  if (envpath == NULL)
    {
      printf("Error: PATH values are NULL");
      return (1);
    }
  
  path_array = splitstring(envpath); /* split PATH values into an array */

  while (path_array[i] != NULL) /* loop through the path array until end */
    {
      printf("%s\n", path_array[i]); /* print each directory in path array */
      i++;
    }
  free(path_array);
  return (0);
}
