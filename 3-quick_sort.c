#include "sort.h"


/**
 * quick_sort - sorts the given array using the quicksort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	int index;

	if (size <= 1)
		return;

	index = partition(array, size);
	quick_sort(array, (size_t)index);
	quick_sort(array + index + 1, size - (size_t)index - 1);
}

/**
 * partition - places the elements less than the pivot in the left side
 * @array: the array to check
 * @size: the size of the array
 * Return: the index of the last swapped element with the pivot
 */
int partition(int *array, size_t size)
{
	size_t i;
	int pivot = array[size - 1];
	int index = 0;

	for (i = 0; i < size - 1; i++)
	{
		if (pivot >= array[i])
		{
			swap_values(array + i, array + index);
			print_array(array, size);
			index++;
		}
	}

	swap_values(array + size - 1, array + index);
	print_array(array, size);

	return (index);
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
