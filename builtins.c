#include "shell.h"

/**
 * update_env - Update environment variables.
 *
 * @old_dir: path of the previous working directory
 * Return: 0
 */
int update_env(char *old_dir)
{
	char *curr_dir;
	size_t i;

	for (i = 0; environ[i]; ++i)
	{
		if (strstr(environ[i], "PWD="))
		{
			curr_dir = NULL;
			curr_dir = getcwd(curr_dir, PATH_MAX);
			environ[i] = strcpy(environ[i] + 4, curr_dir);
			environ[i] -= 4;
			free(curr_dir);
			break;
		}
	}

	for (i = 0; environ[i]; ++i)
	{
		if (strstr(environ[i], "OLDPWD="))
		{
			environ[i] = strcpy(environ[i] + 7, old_dir);
			environ[i] -= 7;
			break;
		}
	}
	return (0);
}

/**
 * _cd - Change the current working directory.
 *
 * @cmd: cmd struct
 * Return: 0
 */
int _cd(cmd_t *cmd)
{
	char *home_dir, *old_dir;
	size_t i;

	old_dir = NULL;
	old_dir = getcwd(old_dir, PATH_MAX);

	/* if no arg, move to home dir instead of printing error message */
	if (cmd->argv[1] == NULL)
	{
		/* find $HOME in environ, then chdir to it */
		for (i = 0; environ[i]; ++i)
		{
			if (strstr(environ[i], "HOME="))
			{
				home_dir = environ[i] + 5;
				break;
			}
		}

		if (chdir(home_dir) == 0)
		{
			printf("\nDirectory changed.\n");
			update_env(old_dir);
		}
		else
			perror("Failed to change directory.\n");
	}
	else
	{
		if (chdir(cmd->argv[1]) == 0)
		{
			printf("\nDirectory changed.\n");
			update_env(old_dir);
		}
		else
			perror("Failed to change directory.\n");
	}
	free(old_dir);
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
