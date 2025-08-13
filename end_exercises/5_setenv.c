#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * _setenv - changes/adds an environment variable
 * @name: name of the env var
 * @value: value to set for env var
 * @overwrite: 0 (don't overwrite) or 1 (overwrite)
 *
 * Return: 0 (success) or 1 (fail)
 */


int _setenv(const char *name, const char *value, int overwrite)
{
	int length = 0; /* hold length of func passed name */
	int i = 0; /* loop counter */
	int newlen = 0; /* store new len for name if overwriting */

	/* check for NULL input */
	if (name == NULL || value == NULL)
	{
		printf("Error");
		return (1);
	}

	length = strlen(name);

	while (environ[i] != NULL) /* loop through environ */
	{
		/* if name and env var name match found */
		if (strncmp(environ[i], name, length) == 0 && environ[i][length] == '=')
		{
			/* var exists - overwrite */
			if (overwrite == 1)
			{
				/* free old var string and replace */
				free(environ[i]);
				/* calc length of new name+value+=+null term */
				newlen = length + strlen(value) + 2;

				/* allocate mem in environ string */
				environ[i] = malloc(newlen);
				/* check for malloc fail */
				if (environ[i] == NULL)
				{
					printf("Error: malloc");
					return (1);
				}
				/* format string name=value in list */
				snprintf(environ[i], newlen, "%s=%s", name, value);
				printf("Overwrite is 1, env var overwritten");
				return (0);
			}

			/* env var exists - do not overwrite */
			else if (overwrite == 0)
			{
				printf("overwrite is 0, env var not overwritten");
				return (0);
			}

		}
		i++;
	}
/* env var doesn't exist - add */
	newlen = length + strlen(value) + 2; /* find length of name+=+value+nullterm */
	/* malloc space and crearte new name=value string */
	char *new_var = malloc(newlen);
	if (new_len == NULL)
	{
		printf("Error: malloc fail\n");
		return (1);
	}
	snprintf(new_var, newlen, "%s=%s", name, value);

	/* Count number of env vars again */
	int count = 0;
	while (environ[count] != NULL)
		count++;

	/* make new arrray for updated env list */
	char **new_environ = malloc(sizeof(char *) * (count + 2));
	if (new_environ == NULL)
	{
		free(new_var);
		printf("Error: malloc failed\n");
		return (1);
	}

	int j = 0;
	/* copy existing env var to new array */
	while (j < count)
	{
		new_environ[j] = environ[j];
		j++;
	}
	/* add new env var string to end of array */
	new_environ[count] = new_var;
/* add NULL to end of array */
	new_environ[count + 1] = NULL;

	/* update environ to point to new env var array */
	environ = new_environ;

	printf("Env var added\n");
	return (0);

}
