#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * _unsetenv - delete env var from env var list
 * @name: name of env var
 * 
 * Return: 0 (success) or 1 (fail)
 */

extern char **environ; /* global var */

int _unsetenv(const char *name)
{
  int i = 0; /* track index position in env var array */
  int name_length = strlen(name); /* store length of name param */

if (name == NULL) /* check for NULL */
{
printf("Error: name is NULL\n");
return (1);
}

while (environ[i] != NULL) /* loop through env var array */
{
    /* if env var found */
 if (strncmp(name, environ[i], name_length) == 0 && environ[i][name_length] == '=')
 {
    free(environ[i]); /* free existing env var */
    while (environ[i] != NULL) /* loop through rest of array */
    {
        environ[i] = environ[i + 1]; /* move everything left by 1 */
        i++;
    }  
    environ[i] = NULL; /* add NULL to end of array */
    printf("Success: environment variable found and deleted\n");
    return (0);
 }
i++;
}
/* env var doesn't exist - no deletion required */
printf("Error: no environment variable found");
return (1);
}
