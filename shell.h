#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * struct Interval - an interval beteween two separators in the string
 * @beg: the beginning, integer
 * @end: the end, integer
 */
typedef struct Interval {
	int end;
	int beg;
} Interval;

int _putchar(char c);

void _strcpy(char *dest, const char *src);
int _strlen(const char *s);
void _strcat(char *dest, const char *src);
bool _strcmp(const char *s1, const char *s2, int beg, int end);
char **_strtok(char *s);

Interval find_str_seq(const char *s, const char *sep, int idx);
void get_str_seq(const char *s, int beg, int end, char **res);
int find_chars_number(const char *s, const char *c, int idx);
void insertion_sort(int arr[], int n);

int change_dir(const char *str, char **env);
void sig_handler(int sig_num);
void exit_handler(char *line, ssize_t length);
char *path_resolver(char **env, char *cmd);
void print_env(char **env);

void write_prompt(int ac);
bool env_handler(char *s, char *env[]);

char *_strrev (char *str);
unsigned int num_len(unsigned int n);
char *_itoa(unsigned int num);
void proc_handler(char *app, char *path, char **toks,
		char *err_msg, unsigned int *c);
void write_error(char *app, char *src, unsigned int err_code, char *msg);

#endif
