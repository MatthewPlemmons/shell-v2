#include "shell.h"

/**
 * parse_builtin - Enumeration for builtin commands.
 *
 * @cmd: struct for command line
 * Return: enum value indicating the requested builtin command.
 */
enum builtin_t parse_builtin(cmd_t *cmd)
{
	if (!strcmp(cmd->argv[0], "exit"))
		return (EXIT);
	if (!strcmp(cmd->argv[0], "cd"))
		return (CD);
	if (!strcmp(cmd->argv[0], "env"))
		return (ENV);
	else
		return (NONE);
}

/**
 * shell_init - initialize shell variables.
 *
 * @cmd: struct containing shell variables
 */
static void shell_init(cmd_t *cmd)
{
	int i;

	cmd->argc = 0;

	for (i = 0; i < MAXARGS; ++i)
		cmd->argv[i] = '\0';
}

/**
 * parser - Parse the command line.
 *
 * @cmdline: command line
 * @cmd: struct for command line
 * Return: int indicating background process or not.
 */
int parser(cmd_t *cmd, char *cmdline)
{
	/*cmd_t cmd;*/
	char *token;
	int bg_proc, i;

	if (cmdline == NULL)
	{
		exit(EXIT_FAILURE);
	}

	shell_init(cmd);
	token = strtok(cmdline, DELIMS);
	for (i = 0; token && i < MAXARGS - 1; ++i)
	{
		cmd->argv[cmd->argc++] = token;
		token = strtok(NULL, DELIMS);
	}

	cmd->argv[cmd->argc + 1] = NULL;
	if (cmd->argc == 0)
		return (1);

	cmd->builtin = parse_builtin(cmd);

	cmd->bg_proc = (*cmd->argv[cmd->argc - 1] == '&');
	if (cmd->bg_proc != 0)
		cmd->argv[--cmd->argc] = NULL;

	return (cmd->bg_proc);
}
