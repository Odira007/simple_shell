#include "shell.h"

/**
 * _strtok - finds and returns the tokens
 * from string s
 * @s: pointer to a string
 * Return: array of strings
 */
char **_strtok(char *s)
{
	int i = 0, tok_beg = 0, tok_end = 0, len = _strlen(s);
	Interval itv;
	char *token;
	char **tokens = NULL;

	tokens = malloc(sizeof(char *) * len);
	if (tokens == NULL)
		return (NULL);

	itv = find_str_seq(s, " \t\r\n", tok_beg);
	tok_end = itv.end;

	token = malloc(sizeof(char) * len);
	if (!token)
		return (NULL);
	get_str_seq(s, tok_beg, tok_end, &token);
	tokens[i] = malloc(_strlen(token) * sizeof(char));
	if (tokens == NULL)
		return (NULL);

	_strcpy(tokens[i], token);

	while (len > tok_beg)
	{
		i++;
		tok_beg = tok_end + 1;
		if (len == tok_beg)
			break;

		itv = find_str_seq(s, " \t\r\n", tok_beg);
		tok_end = itv.end;
		get_str_seq(s, tok_beg, tok_end, &token);

		tokens[i] = malloc(_strlen(token) * sizeof(char));
		_strcpy(tokens[i], token);
	}
	tokens[i] = NULL;
	return (tokens);
}
