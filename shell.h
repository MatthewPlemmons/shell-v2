#ifndef _SHELL_H
#define _SHELL_H

#define MAXARGS 128
#define MAXLINE 1024
#define DELIMS " \t\r\n"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <linux/limits.h>

extern char **environ;

/**
 * struct cmd_s - Structure for command line input.
 *
 * @bg_proc: background process option
 * @argc: argument count
 * @argv: argument vector
 * @builtin_t: enumeration for builtin commands
 */
typedef struct cmd_s
{
	int bg_proc;
	int argc;
	char *argv[MAXARGS];
	enum builtin_t
	{
		NONE, EXIT, CD, ENV
	} builtin;
} cmd_t;

int parser(cmd_t *cmd, char *line);
void _exec(cmd_t *cmd);

void run_cmd(cmd_t *cmd);
void run_builtin_cmd(cmd_t *cmd);

/* builtins.c */
int _cd(cmd_t *cmd);
int _exit_sh(char *line);

char *_getenv(const char *name);
int _setenv(const char *name, const char *value);
int _env(void);

char *_strndup(const char *str, size_t n);
char *_strcat(char *dest, const char *src);
size_t _strlen(const char *s);
size_t _strcspn(const char *s, const char *reject);
int _strncmp(const char *s1, const char *s2, size_t n);

char *_strcpy(char *dest, const char *src);


#endif
