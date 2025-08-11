#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/**
 * main - PPID
 *
 * Return: Always 0.
 */

int main (void)
{
	pid_t pid;
	pid = getpid();
	printf("My process ID is %d\n", pid);

	pid_t parent_pid = getppid();
	printf("My parent process ID is %d\n", parent_pid);

	return (0);
}
