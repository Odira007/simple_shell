#include "shell.h"

/**
 * _strlen - finds the length of a string
 * @s: the string
 * Return: str length
 */
int _strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
