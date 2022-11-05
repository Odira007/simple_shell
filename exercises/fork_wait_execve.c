#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	int i;

	pid = fork();
	if (pid == 0)
	{
		for (i = 0; i <= 4; i++)
		{
			fork();
		}
	}
	printf("I am the child process with ID: %d\n", pid);
	return (0);
}
