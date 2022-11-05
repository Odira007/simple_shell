#include "shell.h"

/**
 * proc_handler - creates and handles the child process
 * @app: the source app, ./hsh
 * @path: command or resolved path to executable
 * (program run by execve)
 * @toks: array of tokens to pass to execve() function
 * (array of pointers to strings passed to new program - path)
 * @err_msg: an error message
 * @c: pointer to errors counter
 * Return: void
 */
void proc_handler(char *app, char *path, char **toks, char *err_msg, unsigned int *c);
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
		exit(-1);
	// if were in the child process
	if (child_pid == 0)
	{
		if (execve(path, toks, NULL) == -1)
		{
			*c = *c + 1;
			//create a function to write error here
			printf("%s\n", *err_msg);
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
}



