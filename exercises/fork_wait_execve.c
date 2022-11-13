#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	char *argv[] = {"ls", "-l", NULL};
	execve("./tmp", argv, NULL);

	return (0);
}
