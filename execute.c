#include "shell.h"


/**
 * run_builtin_cmd - Find correct builtin command to execute.
 *
 * @cmd: struct for command line
 */
void run_builtin_cmd(cmd_t *cmd)
{
	switch (cmd->builtin)
	{
	case EXIT:
		_exit_sh(cmd->argv[0]);
		break;
	case CD:
		_cd(cmd);
		break;
	case ENV:
		_env();
		break;
	default:
		perror("command not found.\n");
	}
}


/**
 * run_cmd - Execute command from command line input.
 *
 * @cmd: struct for command line
 */
void run_cmd(cmd_t *cmd)
{
	pid_t childpid;

	childpid = fork();
	if (childpid < 0)
	{
		perror("fork error");
		_exit_sh(cmd->argv[0]);
	}
	else if (childpid == 0)
	{
		if (execvp(cmd->argv[0], cmd->argv) < 0)
		{
			printf("%s: not found\n", cmd->argv[0]);
			/*perror(cmd->argv[0]);*/
			_exit_sh(cmd->argv[0]);
		}
	}
	else
	{
		if (cmd->bg_proc)
			printf("Child PID: [%d]\n", childpid);
		else
			wait(&childpid);
	}
}

/**
 * _exec - Determine if command is builtin or not and execute it.
 *
 * @cmd: struct for shell variables and command line
 */
void _exec(cmd_t *cmd)
{
	if (cmd->bg_proc == -1)
		return;
	if (cmd->argv[0] == NULL)
		return;
	if (cmd->builtin != NONE)
		run_builtin_cmd(cmd);
	else
		run_cmd(cmd);

}
