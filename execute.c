#include "shell.h"


/**
 * run_builtin_cmd - Find correct builtin command to execute.
 * @line: command line
 * @cmd: struct for command line
 */
void run_builtin_cmd(char *line, cmd_t *cmd)
{
	switch (cmd->builtin)
	{
	case EXIT:
		_exit_sh(line);
		break;
	case CD:
		_cd(cmd);
		break;
	default:
		perror("Unknown command.\n");
	}
}


/**
 * run_cmd - Execute command from command line input.
 * @line: command line
 * @cmd: struct for command line
 * @bg: background process
 */
void run_cmd(char *line, cmd_t *cmd, int bg)
{
	pid_t childpid;

	childpid = fork();
	if (childpid < 0)
	{
		perror("fork error");
		_exit_sh(line);
	}
	else if (childpid == 0)
	{
		if (execvp(cmd->argv[0], cmd->argv) < 0)
		{
			printf("%s: command not found\n", cmd->argv[0]);
			_exit_sh(line);
		}
	}
	else
	{
		if (bg)
			printf("Child PID: [%d]\n", childpid);
		else
			wait(&childpid);
	}
}

/**
 * _exec - Determine if command is builtin or not and execute it.
 *
 * @line: command line
 */
void _exec(char *line)
{
	int bg;
	cmd_t cmd;

	printf("Executing '%s'\n", line);
	bg = parser(line, &cmd);
	if (bg == -1)
		return;
	if (cmd.argv[0] == NULL)
		return;
	if (cmd.builtin != NONE)
		run_builtin_cmd(line, &cmd);
	else
		run_cmd(line, &cmd, bg);

}
