// Moving Zeros To The End

// Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

// move_zeros(10, int [] {1, 2, 0, 1, 0, 1, 0, 3, 0, 1}); // -> int [] {1, 2, 1, 1, 3, 1, 0, 0, 0, 0}

#include <stddef.h>

void move_zeros(size_t len, int arr[len])
{
	int		swapped;
	int		temp;
	size_t	i;
	size_t	j;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (arr[i] != 0)
			i++;
		if (arr[i] == 0)
		{
			j = 1;
			while (arr[i + j] == 0)
				i++;
			if (arr[i + j] != 0 && i + j < len)
			{
				temp = arr[i];
				arr[i] = arr[i + j];
				arr[i + j] = temp;
				swapped = 1;
			}
		}
	}
}


int main()
{
	int	i;
	int	arr[8] = {0, 1, 0, 2, 0, 3, 4, 5};

	move_zeros(8, arr);
	i = 0;
	while (i < 8)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

