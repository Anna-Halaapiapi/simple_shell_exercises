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

		fork_return = fork(); /* create child process */

		if (fork_return == -1) /* check if fork failed */
		{

			perror("Error - fork failed"); /* print error */
			_exit(1); /* exit program */
		}

		if (fork_return == 0) /* code for child process */
		{
			char *argv[2] = {buffer, NULL};/*initialise array*/

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
			free(buffer); /* free user input in buffer */
		}

	}
	return (0);
}
