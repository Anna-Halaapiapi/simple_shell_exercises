#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * main - entry point
 * Description: prints environment using environ
 *
 * Return: 0 (success) or 1 (failure)
 */
  extern char **environ; /* global environment variable */

int main(void)
{

  int i = 0; /* loop counter */

  while (environ[i] != NULL) /* loop through environ array */
    {
      printf("%s\n", environ[i]); /* print environment */
      i++; /* increment i */
    }
  return (0);
}
