#include "sort.h"

/**
 * counting_sort - sorts the given array using the counting algorithm
 * @array: the array to sort
 * @size: thésize of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, max;
	int *frequency;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > (int)max)
			max = array[i];
	}

	frequency = malloc(sizeof(int) * (max + 1));
	if (frequency == NULL)
		return;

	for (i = 0; i < max; i++)
		frequency[i] = 0;

	for (i = 0; i < size; i++)
		frequency[array[i]]++;

	for (i = 1; i <= max; i++)
		frequency[i] += frequency[i - 1];

	print_array(frequency, max + 1);

	for (i = size - 1; i != 0; i--)
		swap_values(array + i, array + frequency[array[i]] - 1);

	swap_values(array + i, array + frequency[array[i]] - 1);

	free(frequency);
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
