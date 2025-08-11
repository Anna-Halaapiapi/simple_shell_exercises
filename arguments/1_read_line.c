#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints "$ ", waits for user to enter command, prints it on next line.
 *
 * Return: 0
 */

int main(void)
{
	char *buffer = NULL; /* store input line from user */
	size_t buffsize = 0; /* store size of buffer */
	ssize_t numsread;/*store num of chars read by getline or -1(EOF/error)*/

	while (1)
	{
		printf("$ "); /* print $ */
		fflush(stdout);/*flush to stdout in case $ is stored in buffer*/

		/* read line from stdin, store chars read*/
		numsread = getline(&buffer, &buffsize, stdin);

		if (numsread == -1) /* check for getline failure or EOF */
		{
			printf("getline end\n");
			break;
		}
		printf("%s", buffer); /* print user input */
	}

	free(buffer); /* free line in buffer */

	return (0);
}
