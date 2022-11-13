#include "shell.h"

/**
 * find_chars_number - helper that finds the number of characters c inside the
 * string s, starting from the index idx
 * @s: string where to search
 * @c: string of characters to search for
 * @idx: the position in the string from where to start
 *
 * Return: the number of occurences of charactes from the string `c`
 */
int find_chars_number(const char *s, const char *c, int idx)
{
	int i, j, q;

	j = q = 0;
	i = idx;

	while (c[j])
	{
		i = idx;
		while (s[i])
		{
			if (s[i] == c[j])
				q++;
			i++;
		}
		j++;
	}
	return (q);
}
