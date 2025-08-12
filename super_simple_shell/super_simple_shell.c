#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * Description: executes a user input command (with full path)
 * Each child is created by same parent
 * Parent waits for a child to term before creating a new child
 *
 * Return: 0 (success) or 1 (failure)
 */

int main(void)
{
	int status; /*  status for wait */
	pid_t fork_return; /* store return from fork */
	char *buffer = NULL; /* store input from user */
	size_t buffsize = 0; /* store size of buffer */
	ssize_t numsread; /*store num of chars read by getline or -1(EOF/err)*/
	char *argv[2]; /* argv array */

	while (1) /* infinite loop */
	{
		printf("#cisfun$ "); /* print prompt */
		fflush(stdout); /*flush prompt in case it's stored in a buffer*/

		/* read user input and store number of chars read */
		numsread = getline(&buffer, &buffsize, stdin);

		if (numsread == -1) /* check for getline error */
		{
			perror("Error - getline failed"); /* print error */
			return (1); /* exit program */
		}

		if (buffer[numsread - 1] == '\n')/* if newline at end */
		{
			buffer[numsread - 1] = '\0';/*replace /n with nullterm*/
		}

		fork_return = fork(); /* create child process */

		if (fork_return == -1) /* check if fork failed */
		{

			perror("Error - fork failed"); /* print error */
			_exit(1); /* exit program */
		}

		if (fork_return == 0) /* code for child process */
		{
			argv[0] = buffer; /* assign array values */
			argv[1] = NULL;

			 /* call execve and check for failure */
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error - execve failed");/*print error */
				_exit(1); /* exit program */
			}
		}
		else
		{
			wait(&status); /* wait for child process to end */
		}

	}
	free(buffer); /* free user input in buffer */
	return (0);
}
