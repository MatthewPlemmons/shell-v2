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
		return EXIT;
	else if (!strcmp(cmd->argv[0], "cd"))
		return CD;
	else
		return NONE;
}

/**
 * parser - Parse the command line.
 *
 * @cmdline: command line
 * @cmd: struct for command line
 * Return: int indicating background process or not.
 */
int parser(char *cmdline, cmd_t *cmd)
{
	char *token;
	int bg_proc, i;

	if (cmdline == NULL)
	{
		exit(EXIT_FAILURE);
	}

	cmd->argc = 0;
	token = strtok(cmdline, DELIMS);
	for (i = 0; token && i < MAXARGS - 1; ++i)
	{
		cmd->argv[cmd->argc++] = token;
		token = strtok(NULL, DELIMS);
	}

	cmd->argv[cmd->argc] = NULL;
	if (cmd->argc == 0)
		return (1);

	cmd->builtin = parse_builtin(cmd);

	bg_proc = (*cmd->argv[cmd->argc - 1] == '&');
	if (bg_proc != 0)
		cmd->argv[--cmd->argc] = NULL;

	return (bg_proc);
}
