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
 * @argc: argument count
 * @argv: argument vector
 * @builtin_t: enumeration for builtin commands
 */
typedef struct cmd_s
{
	int argc;
	char *argv[MAXARGS];
	enum builtin_t
	{
		NONE, EXIT, CD
	} builtin;
} cmd_t;

int parser(char *line, cmd_t *cmd);
void _exec(char *line);

void run_cmd(char *line, cmd_t *cmd, int bg);
void run_builtin_cmd(char *line, cmd_t *cmd);

int _cd(cmd_t *cmd);
int _exit_sh(char *line);

#endif
