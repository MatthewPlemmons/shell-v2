#include "shell.h"

/**
 * main - Command line interpreter.
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on successful execution, 1 otherwise.
 */
int main(int argc, char **argv)
{
	char *prompt;
	char *line;
	size_t n;
	(void) argc;
	(void) argv;

	prompt = "> ";
	while (1)
	{
		line = malloc(sizeof(char) * MAXLINE);
		if (!line)
		{
			exit(EXIT_FAILURE);
		}
		printf("%s", prompt);

		n = MAXLINE;
		n = getline(&line, &n, stdin);
		if ((int) n == -1)
		{
			perror("getline() returned error");
			free(line);
			exit(EXIT_FAILURE);
		}
		line[strlen(line) - 1] = '\0';
		_exec(line);

		free(line);
	}

	return (EXIT_SUCCESS);
}
