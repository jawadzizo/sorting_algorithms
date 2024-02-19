#include "sort.h"


/**
 * selection_sort - sorts an array using the selection sorting algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	int min;
	size_t min_index, curr_index, j;

	for (curr_index = 0; curr_index < size; curr_index++)
	{
		min = array[curr_index];

		for (j = curr_index + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				min_index = j;
			}
		}

		if (array[curr_index] != min)
		{
			swap_values(array + curr_index, array + min_index);
			print_array(array, size);
		}
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
