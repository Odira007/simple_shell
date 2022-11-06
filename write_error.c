#include "shell.h"

/**
 * write_error - writes the exact same error output as /bin/sh
 * @app: source app, ./hsh
 * @src: the command that caused the error
 * @err_code: error counter
 * @msg: error message
 * Return: void
 */
void write_error(char *app, char *src, unsigned int err_code, char *msg)
{
	char *code = _itoa(err_code), *buf = NULL;
	unsigned int len = _strlen(code) + strlen(app)
		+_strlen(src) + strlen(msg) + 6;
	buf = malloc((sizeof(char) + 1) * len);

	if (buf == NULL)
		exit(1);
	_strcpy(buf, app);
	_strcat(buf, ": ");
	_strcat(buf, code);
	_strcat(buf, ": ");
	_strcat(buf, src);
	_strcat(buf, ": ");
	_strcat(buf, msg);

	write(STDOUT_FILENO, buf, len);
}
