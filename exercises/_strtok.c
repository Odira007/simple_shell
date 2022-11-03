#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "My name is Odira";
	char *d = " ";

	char *split = strtok(str, d);

	while (split != NULL)
	{
		printf("[%s]\n", split);
		split = strtok(NULL, d);
	}
	return (0);
}
