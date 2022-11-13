#include "shell.h"

/**
 * sig_handler - takes care of signals
 * @sig_num: a signal
 */
void sig_handler(int sig_num)
{
	if (sig_num == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}
