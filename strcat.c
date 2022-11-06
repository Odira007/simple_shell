#include "shell.h"

/**
 * _strcat - concatenates 2 strings
 * @dest: destination
 * @src: source
 * Return: void
 */
void _strcat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
	{}
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';
}
