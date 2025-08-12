#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

/**
 * main - entry point
 * Description: executes command ls -l /tmp in 5 diff child processes
 * Each child is created by same parent
 * Parent waits for a child to exit before creating a new child
 *
 * Return: 0 (success) or 1 (failure)
 */

int main(void)
{
	pid_t pid, ppid; /* store ppids and pids */
	pid_t fork_return; /* store fork return value */
	int status; /* status for wait */
	int i = 0; /* loop counter */
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL}; /* argv array */

	while (i < 5) /* run loop 5 times */
	{

		fork_return = fork(); /* create child process */

		if (fork_return == -1) /* if fork fails */
		{
			 /* print error and exit program */
			perror("Error - fork failed");
			return (1);
		}

		if (fork_return == 0) /* code for child process */
		{
			ppid = getppid(); /* get parent pid */
			pid = getpid(); /* get child pid */

			printf("The parent process ID is: %d\nThe (child) process ID is: %d\n", ppid, pid);

			/* execute command and check for failure */
			if (execve(argv[0], argv, NULL) == -1)
			{
				/* print error and exit program */
				perror("Error - execve failed");
				_exit(1);
			}
		}

		else /* code for parent process */
		{
			wait(&status);
		}
		i++;
	}
	return (0);
}
