#include <sort.h>

/**
 * shell_sort - sorts the given array using the shellsort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = size / 2;
	size_t i, j;

	while (gap > 0)
	{
		for (i = 0; i + gap < size; i++)
		{
			if (array[i] > array[i + gap])
			{
				swap_values(array + i, array + i + gap);

				for (j = i; j >= gap && array[j] < array[j - gap]; j -= gap)
					swap_values(array + j, array + j - gap);
			}
		}

		print_array(array, size);

		gap /= 2;
	}
}


/**
 * swap_values - swaps the values etween 2 integers
 * @number1: a pointer to the first integer
 * @number2: a pointer to the second integer
 */
void swap_values(int *number1, int *number2)
{
	int temp;

	temp = *number1;
	*number1 = *number2;
	*number2 = temp;
}
