#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - tests the getline function
 * @ac: argument count
 * @av: array of strings of count ac
 */
int main(int ac, char *av[])
{
	/**
	 * getline(char **lineptr, size *n, FILE *stream)
	 * stream: through which text is retrieved(stdin)
	 * n: a buffer of size n is created and the address of the buffer
	 * is stored in *lineptr
	 */
	size_t n;
	char *buffer;

	n = 10;
	buffer = malloc(sizeof(char) * n);
	getline(&buffer, &n, stdin);

	printf("Name: %sBuffer size: %ld\n", buffer, n);
	free(buffer);
	return (0);
}
