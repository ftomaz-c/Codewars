/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pangram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:37:12 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/24 19:12:20 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Detect Pangramgit pull.

// A pangram is a sentence that contains every single letter of the alphabet at least once.
// For example, the sentence "The quick brown fox jumps over the lazy dog" is a pangram, because
// it uses the letters A-Z at least once (case is irrelevant).

// Given a string, detect whether or not it is a pangram. Return True if it is, False if not.
// Ignore numbers and punctuation.

#include <stdbool.h>

bool is_pangram(const char *str_in)
{
	int num_letters;
	int i;
	int j;

	num_letters = 26;
	i = 0;
	while (i < num_letters)
	{
		j = 0;
		while (str_in[j] != '\0')
		{
			// Check for a match with the current alphabet letter (uppercase or lowercase)
			if (str_in[j] == ('A' + i) || str_in[j] == ('a' + i))
				break;
			j++;
		}
		// If current letter wasn't found and there are still letters left to check
		if (str_in[j] == '\0' && i != num_letters)
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int	main ()
// {
// 	char	*str1;
// 	char	*str2;
// 	char	*str3;

// 	str1 = "abcdefghijklmnopqrstuvwxy";
// 	str2 = "ABCDEFGHIJKLMNOPQRSTUVWXY ";
// 	str3 = "J.CNdK~!U%AVILn,ResxqOamabPvri VfDFESgGpyXhtokQauTWHuM";
// 	printf("--- %s ---\n", str1);
// 	if (is_pangram(str1) == 1)
// 		printf("str1 is a Pangram\n");
// 	else
// 		printf("str1 isn't a Pangram\n");
// 	printf("\n--- %s ---\n", str2);
// 	if (is_pangram(str2) == 1)
// 		printf("str2 is a Pangram\n");
// 	else
// 		printf("str2 isn't a Pangram\n");
// 	printf("\n--- %s ---\n", str3);
// 	if (is_pangram(str3) == 1)
// 		printf("str3 is a Pangram\n");
// 	else
// 		printf("str3 isn't a Pangram\n");
// }
