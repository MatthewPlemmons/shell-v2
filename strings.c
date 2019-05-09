#include "shell.h"


/**
 * _strndup - duplicate a string.
 *
 * @str: string to duplicate
 * @n: initial bytes of `str` to duplicate
 * Return: pointer to the duplicated string.
 */
char *_strndup(const char *str, size_t n)
{
	char *a;
	size_t i;

	if (!str)
		return (NULL);

	a = malloc(sizeof(char) * (n + 1));
	if (!a)
		return (NULL);

	for (i = 0; i < n && str[i]; ++i)
		a[i] = str[i];

	a[i] = '\0';
	return (a);
}

/**
 * _strcat - concatenate two strings.
 *
 * @dest: string 1
 * @src:  string 2
 * Return: pointer to the concatenated string.
 */
char *_strcat(char *dest, const char *src)
{
	char *s;

	s = dest;
	while (*dest != '\0')
		dest++;

	while (*src != '\0')
		*dest++ = *src++;

	*dest = '\0';
	return (s);
}

/**
 * _strlen - calculate the length of a string.
 *
 * @s: input string
 * Return: number of bytes in `s`.
 */
size_t _strlen(const char *s)
{
	int i;

	for (i = 0; s[i]; ++i)
		;

	return (i);
}

/**
 * _strcspn - search initial segment of `s` for bytes not in `reject`.
 *
 * @s: string to search
 * @reject: bytes to search for
 * Return: number of bytes in the initial segment of `s` which are
 *         not in `reject`.
 */
size_t _strcspn(const char *s, const char *reject)
{
	size_t i, j;

	for (i = 0; s[i]; ++i)
	{
		for (j = 0; reject[j]; ++j)
		{
			if (s[i] == reject[j])
				return (i);
		}
	}
	return (i);
}

/**
 * _strncmp - compare the first n bytes of two strings.
 *
 * @s1: string 1
 * @s2: string 2
 * @n: initial bytes to compare
 * Return: 0 if the strings match, non-zero integer otherwise.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (*(s1 + i) && *(s2 + i) && i < n)
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		++i;
	}
	return (0);
}
