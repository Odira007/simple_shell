#include "shell.h"

/**
 * main - the root of the shs
 * @ac: arguments counter
 * @av: arguments vector
 * @env: an array of environmental vars, key=value
 *
 * Return: exit code / error code
 */
int main(int ac, char *av[], char *env[])
{
	unsigned int c = 0;
	size_t buf;
	ssize_t ch;
	char **toks = NULL;
	char *path = NULL, *line = NULL, *err_msg = "not found\n";

	while (true)
	{
		signal(SIGINT, sig_handler);

		if (isatty(STDIN_FILENO))
			write_prompt(ac);
		ch = getline(&line, &buf, stdin);
		toks = _strtok(line);

		if (!env_handler(toks[0], env))
		{
			exit_handler(line, ch);
			path = path_resolver(env, toks[0]);
			proc_handler(av[0], path, toks, err_msg, &c);
		}
	}
	return (0);
}
