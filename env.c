#include "shell.h"

/**
 * _getenv - get an environment variable.
 *
 * @name: variable name
 * Return: pointer to the variable's value, or NULL if there is no match.
 */
char *_getenv(const char *name)
{
	char *val;
	size_t i, n, len;

	n = _strlen(name);
	for (i = 0; environ[i]; ++i)
	{
		if (environ[i][0] != name[0])
			continue;
		if (_strncmp(environ[i], name, n) == 0)
		{
			len = _strlen(environ[i]) - n;
			val = strndup(environ[i] + n, len);
			if (!val)
				break;

			return (val);
		}
	}

	return (NULL);
}

/**
 * _setenv - change or add and environment variable.
 *
 * @name: variable name
 * @value: variable value
 * Return: 0 on success, or -1 on error.
 */
int _setenv(const char *name, const char *value)
{
	char *new, **env;
	size_t i, k, len, size;

	k = _strlen(name);
	len = _strlen(value) + k + 1;
	new = malloc(sizeof(char) * len);
	if (!new)
		return (-1);
	new = _strcpy(new, name);
	_strcat(new, value);

	for (i = 0; environ[i]; ++i)
	{
		if (environ[i][0] != name[0])
			continue;
		if (_strncmp(environ[i], name, k) == 0)
		{
			environ[i] = new;
			return (0);
		}
	}
	env = (char **)malloc(sizeof(char *) * (i + 2));
	if (!env)
		return (-1);
	size = i;
	for (i = 0; i < size; ++i)
		env[i] = environ[i];
	env[i] = new;
	env[i + 1] = NULL;
	environ = env;

	return (0);
}

/**
 * _env - list environment variables.
 *
 * Return: 0
 */
int _env(void)
{
	int i;

	for (i = 0; environ[i]; ++i)
		printf("%s\n", environ[i]);
	return (0);
}
