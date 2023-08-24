// Convert a Number to a String

// We need a function that can transform a number (integer) into a string.

// What ways of achieving this do you know?

// In C, return a dynamically allocated string that will be freed by the test suite.
// Examples (input --> output):

// 123  --> "123"
// 999  --> "999"
// -100 --> "-100"

#include <stdlib.h>
#include <limits.h>

int count_digits(int nbr) {
	int count;

	count = 0;
	if (nbr <= 0)
		count++;
	while (nbr != 0) {
		nbr /= 10;
		count++;
	}
	return (count);
}

char *number_to_string(int number) {
	char	*str;
	int		sign;
	int		len;

	if (number == INT_MIN) {
		str = calloc (sizeof(char) , 12);
		str = "-2147483647";
		return (str);
	}
	len = count_digits(number);
	str = calloc(sizeof(char), len + 1);
	if (number == 0)
		str[0] = '0';
	if (number < 0) {
		str[0] = '-';
		number *= -1;
	}
	len -= 1;
	while (number > 0) {
		str[len] = number % 10 + '0';
		number /= 10;
	len--;
	}
	return (str);
}

/* #include <stdio.h>

int	main()
{
	char	*str;
	int		number;

	number = -2147483647;
	str = number_to_string(number);
	printf("%s\n", str);
	free(str);
} */

/* Learned that could also have used asprintf... didn't know tho about this function!
		New tool unlocked!

#include <stdio.h>

const char* number_to_string(int number) {
	char *s;
	asprintf(&s, "%d", number);
	return s;
} */
