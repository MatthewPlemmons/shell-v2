#include "shell.h"

/**
 * _cd - Change the current working directory.
 *
 * @cmd: cmd struct
 * Return: 0
 */
int _cd(cmd_t *cmd)
{
	char *pwd, *oldpwd;
	size_t i;

	oldpwd = NULL;
	oldpwd = getcwd(oldpwd, PATH_MAX);
	if (cmd->argv[1] == NULL)
	{
		pwd = _getenv("HOME=");

		if (chdir(pwd) == 0)
		{
			_setenv("OLDPWD=", oldpwd);
			_setenv("PWD=", pwd);
		}
		else
			perror("Failed to change directory.\n");
	}
	else
	{
		if (cmd->argv[1][0] == '-')
		{
			pwd  = _getenv("OLDPWD=");

			if (chdir(pwd) == 0)
			{
				_setenv("OLDPWD=", oldpwd);
				_setenv("PWD=", pwd);
			}
		}
		else if (chdir(cmd->argv[1]) == 0)
		{
			pwd = _strndup(cmd->argv[1], sizeof(cmd->argv[1]));
			_setenv("OLDPWD=", oldpwd);
			_setenv("PWD=", pwd);
		}
		else
			perror("Failed to change directory.\n");
	}

	return (0);
}


/**
 * _exit_sh - Free line pointer and exit the shell.
 *
 *
 * @line: command line string.
 * Return: 0
 */
int _exit_sh(char *line)
{
	free(line);
	exit(EXIT_SUCCESS);
}
