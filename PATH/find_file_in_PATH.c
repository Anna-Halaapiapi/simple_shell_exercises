#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
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
 * main - entry point
 * Description: looks for files in the current PATH
 *
 * Return: 0 (success) or 1 (failure)
 */
int main(int argc, char **argv)
{
  struct stat st;
  char **path_array;
  /* get PATH env var */
  char *envpath = getenv("PATH");
  int i = 0;
  char full_path[1024]; /* biffer to build full path */
  
  /* handle getenv error */
  if (envpath == NULL)
  {
    perror("Error - path is NULL");
    return (1);
  }

  /* split path into directories */
  path_array = splitstring(envpath);
  /* loop through each path in path_array */
  while (path_array[i] != NULL)
    {
      /* copy each path to full path buffer */
      strcpy(full_path, path_array[i]);
      /* add / to end */
      strcat(full_path, "/");
      /* add file name */
      strcat(full_path, argv[1]);

      /* check if file exists */
      if (stat(full_path, &st) == 0)
	{
	  /* print found and full path */
	  printf("Found: %s\n", full_path);
	  return (0);
	}
      i++;
    }
  /* if not found in loop- print not found */
  printf("File not found\n");
  return (1);
}
