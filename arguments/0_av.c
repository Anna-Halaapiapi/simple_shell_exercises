#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/**
 * main - prints all arguments without using argc
 *
 * Return: 0
 */

int main(int ac, char **av)
{
	(void)ac;

	int i = 1;

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
		return (0);
}
