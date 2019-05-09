#include "shell.h"

/**
 * _strcpy - copy a string.
 *
 * @dest: pointer to copy to
 * @src: pointer to copy from
 * Return: pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	i = 0;
	for (i = 0; src[i] != '\0'; ++i)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
