#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


typedef struct node {
    char *dir;
    struct node *next;
} node_t;


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
 * build_list - split values (dirs) in PATH
 * build a linked list from PATH values
 *
 * Return: head of list
 */

node_t *build_list(void)
{
	char **path_array; /* hold path array */
	char *envpath = getenv("PATH"); /* get dirs in PATH */
	node_t *head = NULL; /* node for head of list */
	node_t *tail = NULL; /* node for end of list */
	node_t *newnode = NULL; /* node to create new node */

	if (envpath == NULL)
	{
		printf("Error");
		return (1);
	}

	path_array = splitstring(envpath); /* split PATH values into an array */

	while (path_array[i] != NULL) /* loop through PATH vals/dirs */
	{
		/* make a node */
		newnode = malloc(sizeof(node_t));

		if (newnode == NULL)/* check for malloc fail */
		{
			printf("Error: malloc fail");
			return (NULL);
		}

		/* set node vals */
		newnode->dir = strdup(path_array[i]);
		newnode->next = NULL

			if (head == NULL)
			{
				head = newnode;
				tail = newnode;
			}

			else
			{
				tail->next = newnode;
				tail = newnode;
			}
		i++;
	}
	free(path_array);
	return (head);
}
