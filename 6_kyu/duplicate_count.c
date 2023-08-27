// Count the number of Duplicates

// Write a function that will return the count of distinct case-insensitive alphabetic characters and numeric digits that occur more than once in the input string. The input string can be assumed to contain only alphabets (both uppercase and lowercase) and numeric digits.
// Example

// "abcde" -> 0 # no characters repeats more than once
// "aabbcde" -> 2 # 'a' and 'b'
// "aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
// "indivisibility" -> 1 # 'i' occurs six times
// "Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
// "aA11" -> 2 # 'a' and '1'
// "ABBA" -> 2 # 'A' and 'B' each occur twice

#include <stddef.h>

size_t duplicate_count(const char *text)
{
	size_t	counter;
	int		duplicate[128] = {0};
	int		i;

	while (*text)
	{
		char character = *text;
		if (character >= 'A' && character <= 'Z')
			character += 'a' - 'A';
		if (character >= 'a' && character <= 'z')
			duplicate[character] += 1;
		if (character >= '0' && character <= '9')
			duplicate[character] += 1;
		text++;
	}
	counter = 0;
	i = 0;
	while (i < 128)
	{
		if (duplicate[i] > 1)
			counter++;
		i++;
	}
	return (counter);
}

// #include <stdio.h>

// int	main()
// {
// 	char *text1 = "Wohg694MiaM7eaFjoscrDoR9UZ8BA";
// 	char *text2 = "99redballons99bottlesofbeeronthewall";

// 	printf("%zu\n", duplicate_count(text1));
// 	printf("%zu\n", duplicate_count(text2));
// }
