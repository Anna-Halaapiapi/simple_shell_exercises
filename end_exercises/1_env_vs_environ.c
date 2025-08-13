#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * main - entry point
 * Description: prints address of env and environ
 *
 * Return: 0 (success) or 1 (failure)
 */

int main(int ac, char **av, char **env)
{
 extern char **environ; /* global environment variable */

 /* print addresses */
 printf("Address of env: %p\n", (void *)env);
 printf("Address of environ: %p\n", (void *)environ);

 return (0);
}
