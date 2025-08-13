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
  int i, arg_i = 1, found_flag = 0;
  char full_path[1024]; /* biffer to build full path */
  
  /* handle errors */
  if (envpath == NULL)
  {
    perror("Error - path is NULL");
    return (1);
  }
  if (argc < 2)
    {
      printf("Error: incorrect usage. Correct usage is: %s filename\n", argv[0]);
      return (1);
    }

  /* split path into directories */
  path_array = splitstring(envpath);

  while (arg_i < argc) /* loop through multiple filenames */
    {
      found_flag = 0;
      i = 0;
      
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
	  printf("File found in the following location: %s\n", full_path);
	  found_flag = 1;
	  break;
	}
      i++;
    }
  if (found_flag = 0)
    {
      printf("%s: not found\n", argv[arg_i]);
    }
  arg_i++;
    }
  free(path_array);
  return (1);
}
