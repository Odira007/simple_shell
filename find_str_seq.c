#include "shell.h"

/**
 * find_str_seq - finds the index of the separator `sep`
 * inside the string `s`, starting from the index `idx`
 * @s: string constant where to search
 * @sep: the separator(s) to search for
 * @idx: the position of the string from where to start
 *
 * Return: the index of the `sep` inside the string `s`
 */
Interval find_str_seq(const char *s, const char *sep, int idx)
{
	Interval itv;
	int i = 0, j = 0, k = 1;
	int array[1024];
	int o = 0;

	/* printf("number of separators in the string: %d\n", n); */
	array[0] = idx;
	while (sep[i])
	{
		j = idx;
		while (s[j])
		{
			if (s[j] == sep[i])
			{
				array[k] = j;
				k++;
			}
			j++;
		}
		i++;
	}
	o = sizeof(array) / sizeof(array[0]);
	insertion_sort(array, o);

	itv.beg = array[0];
	itv.end = array[1];

	return (itv);
}
