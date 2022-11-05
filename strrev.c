#include "shell.h"

/**
 * _strrev - reverses a string
 * @str: the string
 * Return: reversed str
 */
char *_strrev (char *str)
{
	int len;
	int i;
	char temp;

	len = _strlen(str);

	for (i = 0; i <= len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
	return (str);
}
