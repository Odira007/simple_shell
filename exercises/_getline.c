#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

size_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	if (lineptr == NULL || stream == NULL)
		return (-1);
}
