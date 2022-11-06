#include "shell.h"

/**
 * write_prompt - prints "$ " and waits for a user
 * to enter a command
 * @ac: argument count
 * Return: void
 */
void write_prompt(int ac)
{
	if (ac == 1)
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}
