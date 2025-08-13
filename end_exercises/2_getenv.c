#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * getenv - gets an environment variable
 * Description: search env array, look for name = VAR, return VALUE
 *
 * Return: env variable value
 */

 extern char **environ; /* global environment variable */

char *_getenv(const char *name)
{
  int i = 0; /* loop counter */
  int length = strlen(name); /* length of name */

  while (environ[i] != NULL) /* loop through environ */
    {

      if (strncmp(environ[i], name, length) == 0 && environ[i][length] == '=')/* if match found */
	{
	  return (environ[i]);
	}

	    i++;
    }
      return NULL;
}
  /* simple test */
  int main(int ac, char **av)
  {
    char *value;

    if (ac < 2)
      {
	printf("Error - not enough arguments");
	return (1);
      }
    
    value = _getenv(av[1]);
    
    if (value != NULL)
      {
	printf("%s\n", value);
	return (0);
      }

    else
      {
	printf("environment variable not found");
      }
    return (1);
  }
