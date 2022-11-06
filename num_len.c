#include "shell.h"

/**
 * num_len - find length of a number as if
 * it were a string
 * @n: the number
 * Return: num length
 */
unsigned int num_len(unsigned int n)
{
	unsigned int len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
