#include "shell.h"

/**
 * _strcmp - compares 2 strings
 * @s1: first string for comparison
 * @s2: second string for comparison
 * @beg: beginning of the interval
 * @end: end of the interval
 *
 * Return: the result of comparison between two sequences
 */
bool _strcmp(const char *s1, const char *s2, int beg, int end)
{
	if (!s1 && !s2)
		return (true);

	if (!s1 || !s2 || beg > end)
		return (false);

	do {
		if (s1[beg] != s2[beg])
			return (false);
		beg++;
	} while (beg != end);

	return (true);
}
