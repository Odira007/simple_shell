#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * main - prints the child and parent process IDs
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	pid_t parent_pid;

	child_pid = getpid();
	parent_pid = getppid();
	printf("child PID: %u\nparent PID: %u\n", child_pid, parent_pid);
	return (0);
}
