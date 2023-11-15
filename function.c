#include "main.h"
/**
 *_strlen- returns the length
 *@s: pointer from type int
 *Return: returns count
 */
int _strlen(char *s)
{
	int count = 0;

	while (*s++)
	count++;
	return (count);
}
/**
 * _strcmp - compares
 *@s1: string 1
 *@s2: string 2
 *Return: returns 1 or 0 if true or false
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
