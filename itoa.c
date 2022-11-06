#include "shell.h"

/**
 * _itoa - converts an integer to string
 * @num: integer value to be converted
 * Return: converted int
 */
char *_itoa(unsigned int num)
{
	const int base = 10;
	int i = 0, rem = 0, len = num_len(num);
	char *str = NULL;

	if (num == 0)
	{
		str = malloc(sizeof(char));
		str = '\0';
		return (str);
	}
	str = malloc((sizeof(char) + 1) * len);

	while (num != 0)
	{
		rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num /= base;
	}
	str[i] = '\0';
	return (_strrev(str));
}
