// Does my number look big in this?

// A Narcissistic Number (or Armstrong Number) is a positive number which is
// the sum of its own digits, each raised to the power of the number of digits
// in a given base. In this Kata, we will restrict ourselves to decimal (base 10).

// For example, take 153 (3 digits), which is narcissistic:
//     1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153

// and 1652 (4 digits), which isn't:
//     1^4 + 6^4 + 5^4 + 2^4 = 1 + 1296 + 625 + 16 = 1938

// The Challenge:

// Your code must return true or false (not 'true' and 'false') depending
// upon whether the given number is a Narcissistic number in base 10.

// This may be True and False in your language, e.g. PHP.

// Error checking for text strings or other invalid inputs is not required,
//only valid positive non-zero integers will be passed into the function.

#include <stdbool.h>
#include <stdlib.h>

// count the digits in a number
int  count_digits(int num)
{
	int count;

	count = 0;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return(count);
}

// power of a number with recursion
int power(int x, int y)
{
	if (y == 0)
		return 1;
	else
		return x * power(x, y - 1);
}

bool narcissistic(int num)
{
	int *tab;
	int len;
	int i;
	int	original;
	int result;

	original = num;
	len = count_digits(num);
	tab = calloc(sizeof(int), len); // alloc memory to store the digits in a tab
	i = len - 1;
	while (num != 0)
	{
		tab[i] = num % 10; //store each digits in the tab
		num /= 10;
		i--;
	}
	result = 0;
	i = 0;
	while(i < len)
	{
		result += power(tab[i], len); // apply power to every digit and accumulate the result
		i++;
	}
	free (tab); // free alloced memory
	return (result == original); //return true if matches the original
}

//#include <math.h> to use log10 and pow;
// int	len = log10(num) + 1 - finds the exponent to which 10 must be raised to
//								get the value of num. Adding 1 will give the number of digits.

// could also have use the bit shift:
	// while (num != 0)
	// {
	// 	num >>= 1; // Right-shift by 1 (equivalent to dividing by 2)
	// 	count++;
	// }

/* #include <stdio.h>

int main()
{
	int	num;

	num = 7;
	if (narcissistic(num))
		printf ("%d, is narcissistic.\n", num);
	else
		printf ("%d, is not narcissistic.\n", num);
}
 */
