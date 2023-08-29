// Break camelCase

// Complete the solution so that the function will break up camel casing, using a space between words.
// Example

// "camelCasing"  =>  "camel Casing"
// "identifier"   =>  "identifier"
// ""             =>  ""

#include <stddef.h> // NULL
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char*	solution(const char *camelCase)
{
	char	*solution;
	int	extra_spaces;
	int	len;
	int	i;

	extra_spaces = 0;
	i = 0;
	len = ft_strlen(camelCase);
	while (i < len)
	{
		if (camelCase[i] >= 'A' && camelCase[i] <= 'Z')
			extra_spaces++;
		i++;
	}

	solution = (char *)malloc(sizeof(char) * len + extra_spaces + 1);
	if (!solution)
		return (NULL);
	i = 0;
	while(*camelCase)
	{
		if (*camelCase >= 'A' && *camelCase <= 'Z')
			solution[i++] = ' ';
		solution[i++] = *camelCase++;
	}
	solution[i] = '\0';
	return (solution);
}

// #include <stdio.h>

// int	main()
// {
// 	const char	*str;
// 	char		*new_str;

// 	str = "camelCase";
// 	new_str = solution(str);
// 	printf("%s\n", new_str);
// }
