#include "shell.h"

/**
 * path_resolve_helper - helper function that resolves
 * a PATH to the executable. Runs only if PATH global
 * variable isn't empty
 * @path: the PATH= string from the environment
 * @cmd: the command to search for
 *
 * Return: resolved path to executable, or command as is
 * if unable to resolve
 */
char *path_resolve_helper(const char *path, char *cmd)
{
	int path_len = 0, tok_beg = 0, tok_end = 5;
	char *tok, *bin;
	Interval itv;

	path_len = _strlen(path);
	tok_beg = tok_end + 1; /* separator */
	itv = find_str_seq(path, ":", tok_beg);
	tok_end = itv.end;

	tok = malloc((sizeof(char) + 1) * path_len);
	if (!tok)
		return (NULL);
	bin = malloc(sizeof(path) + sizeof(cmd));
	if (!bin)
		return (NULL);

	get_str_seq(path, tok_beg, tok_end, &tok);
	_strcpy(bin, tok);
	_strcat(bin, "/");
	_strcat(bin, cmd);

	while (access(bin, F_OK) == -1)
	{
		if (path_len == tok_end)
			return (cmd);

		tok_beg = tok_end + 1; /* separator */
		itv = find_str_seq(path, ":", tok_beg);
		tok_end = (itv.end > path_len) ? path_len : itv.end;
		get_str_seq(path, tok_beg, tok_end, &tok);
		_strcpy(bin, tok);
		_strcat(bin, "/");
		_strcat(bin, cmd);
	}
	return (bin);
}

/**
 * path_resolver - resolves the PATH to a commpand `cmd`
 * using the environment `env`
 * @env: the pointer to a environ/argv
 * @cmd: the string with a command
 *
 * Return: the resolved path to executable `cmd`, if it
 * exists, otherwise the `cmd` as is
 */
char *path_resolver(char **env, char *cmd)
{
	char *path;
	int c, path_len = 0, tok_beg = 0, tok_end = 5;
	char *resolved_path = NULL;

	for (c = 0; env[c]; c++)
		if (_strcmp("PATH=", env[c], tok_beg, tok_end - 1))
			path = env[c];

	path_len = _strlen(path);

	if (path_len == 5)
		exit(1);

	resolved_path = path_resolve_helper(path, cmd);

	return (resolved_path);
}
