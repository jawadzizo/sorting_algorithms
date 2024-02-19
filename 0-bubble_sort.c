#include "sort.h"


/**
 * bubble_sort - sorts the array in ascending order
 * @array: the array to be sorted
 * @size: the size of the given array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, index;
	int *current, *next;

	if (size < 2)
		return;

	for (index = 0; index < size; index++)
	{
		for (i = 0; i < size - index - 1; i++)
		{
			current = array + i;
			next = array + i + 1;

			if (*current > *next)
			{
				swap_values(current, next);
				print_array(array, size);
			}
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
