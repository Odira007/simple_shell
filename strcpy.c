#include "shell.h"

/**
 * _strcpy - copies a string src into dest
 * @dest: destination
 * @src: source
 * Return: dest
 */
void _strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = src[i];
}
