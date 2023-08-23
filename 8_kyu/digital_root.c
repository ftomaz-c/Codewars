/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digital_root.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:35:11 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/08/23 11:37:39 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Sum of Digits / Digital Root

// Digital root is the recursive sum of all the digits in a number.

// Given n, take the sum of the digits of n. If that value has more than one digit, continue reducing in this way until a single-digit number is produced. The input will be a non-negative integer.
// Examples

//     16  -->  1 + 6 = 7
//    942  -->  9 + 4 + 2 = 15  -->  1 + 5 = 6
// 132189  -->  1 + 3 + 2 + 1 + 8 + 9 = 24  -->  2 + 4 = 6
// 493193  -->  4 + 9 + 3 + 1 + 9 + 3 = 29  -->  2 + 9 = 11  -->  1 + 1 = 2

int digital_root(int n)
{
	int	result;

	result = 0;
	if (n > 9)
	{
		result += digital_root(n / 10); // Recursive case: Divide the number and accumulate digits.
		n %= 10;  // Get the last digit.
	}
	result += n;  // Accumulate the current digit to the result.
	if (result > 9)
		return(digital_root(result)); // Recurse for when the accumulated result is bigger then 1 digit.
	return (result);  // Return the digital root.
}

// #include <stdio.h>

// int	main()
// {
// 	int	n;

// 	n = 0;
// 	int result = digital_root(n);
// 	printf("%d\n", result);
// }
