#include <stdio.h>

/**
 * main - print all items in av without ac
 *
 * Return: Always 0.
 */
int main(int ac, char *av[])
{
	(void)ac;

	while (*av)
	{
		printf("%s\n", *av++);
	}
	return (0);
}
