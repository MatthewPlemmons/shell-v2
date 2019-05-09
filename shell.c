#include "shell.h"

#define PROMPT_SIZE 3

/**
 * main - Command line interpreter.
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on successful execution, 1 otherwise.
 */
int main(int argc, char **argv)
{
	cmd_t cmd;
	char *line;
	size_t n;
	int bg_proc;
	(void) argc, (void) argv;

	const char *prompt = "> ";

	while (1)
	{
		line = malloc(sizeof(char) * MAXLINE);
		if (!line)
		{
			exit(EXIT_FAILURE);
		}
		printf("%s", prompt);

		n = MAXLINE;
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		line[strlen(line) - 1] = '\0';
		parser(&cmd, line);
		_exec(&cmd);
		free(line);
	}

	return (EXIT_SUCCESS);
}
