/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:43:38 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/24 19:03:57 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Binary Addition

// Implement a function that adds two numbers together and returns their sum in binary.
// The conversion can be done before, or after the addition.

// The binary number returned should be a string.

// Examples:(Input1, Input2 --> Output (explanation)))

// 1, 1 --> "10" (1 + 1 = 2 in decimal or 10 in binary)
// 5, 9 --> "1110" (5 + 9 = 14 in decimal or 1110 in binary)

char *binary_add (unsigned a, unsigned b, char *binary)
{
	unsigned long long	sum;
	unsigned long long	tmp;
	int					index;

	// calculate the sum of the two binary numbers.
	sum = (unsigned long)a + (unsigned long)b;
	tmp = sum;
	if (tmp == 0)
		index = 1;
	else
		index = 0;

	// reversing the binary string
	while (tmp != 0)
	{
		tmp /= 2;
		index++;
	}
	binary[index--] = '\0';

	// storing the sum in the string as binary.
	while (index >= 0)
	{
		binary[index] = (sum & 1) + '0';
		sum >>= 1; // moves de sum 1 position to the right. equivalent of dividing the sum by 2 but more efficient.
		index--;
	}
	return binary;
}

// #include <stdio.h>

// int	main()
// {
// 	unsigned	a;
// 	unsigned	b;
// 	char		binary[33];

// 	a = 4294967295;
// 	b = 4294967295;
// 	printf("expected: 111111111111111111111111111111110\n");
// 	binary_add(a, b, binary);
// 	printf("Binary sum: %s\n", binary);
// }

// best solution:

// (...)
// typedef unsigned long long ull;

// unsigned bitlen (ull n)
// {
// 	return (n == 0) ? 0 : (1 + bitlen(n >> 1));
// }

// char *binary_add (unsigned a, unsigned b, char *binary)
// {
// 	(...)
// 	ull sum = (ull)a + (ull)b;
// 	unsigned length = (sum == 0) ? 1 : bitlen(sum);
// 	(...)
// }

