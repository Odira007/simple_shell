#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * main - gets the max process id a file can have
 *
 * Return: Always 0.
 */
int main(void)
{
	size_t op, rd;
	char *pid_max;
	char *buffer;

	pid_max = "/proc/sys/kernel/pid_max";
	buffer = malloc(sizeof(char) * 1024);

	if (*pid_max == -1)
		return (-1);
	op = open(pid_max, O_RDONLY, 700);
	rd = read(op, buffer, 1024);
	if (op == -1 || rd == -1)
	{
		free(buffer);
		printf("The %s file cannot be opened or read\n", pid_max);
		return (-1);
	}
	printf("/proc/sys/kernel/pid_max: %s", buffer);
	printf("rd size: %lu\n", rd);

	return (0);
}
