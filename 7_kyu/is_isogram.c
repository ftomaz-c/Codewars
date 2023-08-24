/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_isogram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:00:33 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/24 10:37:21 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// An isogram is a word that has no repeating letters, consecutive or non-consecutive.
// Implement a function that determines whether a string that contains only letters is an isogram.
// Assume the empty string is an isogram. Ignore letter case.

// Example: (Input --> Output)

// "Dermatoglyphics" --> true "aba" --> false "moOse" --> false (ignore letter case)

// isIsogram "Dermatoglyphics" = true
// isIsogram "moose" = false
// isIsogram "aba" = false

#include <stdbool.h>

bool IsIsogram (const char *string)
{
	bool	encountered[128] = {false};
	int		current_char;
	int		i;

	i = 0;
	while (string[i] != '\0')
	{
		current_char = string[i];
		if (current_char >= 'A' && current_char <= 'Z')
			current_char += ('a' - 'A');
		if (encountered[current_char])
			return(false);
		encountered[current_char] = true;
		i++;
	}
	return (true);
}

// #include <stdio.h>

// int	main ()
// {
// 	char	*str1;
// 	char	*str2;
// 	char	*str3;

// 	str1 = "abcde";
// 	str2 = "";
// 	str3 = "aA";
// 	printf("--- %s ---\n", str1);
// 	if (IsIsogram(str1) == 1)
// 		printf("str1 is an Isogram\n");
// 	else
// 		printf("str1 isn't an Isogram\n");
// 	printf("\n--- %s ---\n", str2);
// 	if (IsIsogram(str2) == 1)
// 		printf("str2 is an Isogram\n");
// 	else
// 		printf("str2 isn't an Isogram\n");
// 	printf("\n--- %s ---\n", str3);
// 	if (IsIsogram(str3) == 1)
// 		printf("str3 is an Isogram\n");
// 	else
// 		printf("str3 isn't an Isogram\n");
// }
