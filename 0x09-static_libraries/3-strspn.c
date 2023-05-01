/**
* _strspn - Gets the length of a prefix substring
* @s: The string to search
* @accept: The prefix to be measured
*
* Return: The number of bytes in the initial segment of `s`
*         consisting entirely of bytes from `accept`.
*/

unsigned int _strspn(char *s, char *accept)

{
	unsigned int count = 0;

	while (*s != '\0')
	{
		char *a = accept;

		while (*a != '\0' && *s != *a)
			a++;

		if (*a == '\0')
			return count;

		count++;
		s++;
	}

	return count;
}
