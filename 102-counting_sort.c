#include "sort.h"

/**
 * max - Get the maximum value in an array of integers
 * @array: An array of integers
 * @size: The size of the array
 * Return: The maximum integer in the array
 */
int max(int *array, int size)
{
	int m, n;

	for (m = array[0], n = 1; n < size; n++)
	{
		if (array[n] > m)
			m = array[n];
	}

	return (m);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 * @array: An array of integers
 * @size: The size of the array
 * Return : void
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sort;
  int m, n;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	m = max(array, size);
	count = malloc(sizeof(int) * (m + 1));
	if (count == NULL)
	{
		free(sort);
		return;
	}

	for (n = 0; n < (m + 1); n++)
		count[i] = 0;
	for (n = 0; n < (int)size; n++)
		count[array[n]] += 1;
	for (n = 0; i < (m + 1); n++)
		count[n] += count[n - 1];
	print_array(count, m + 1);

	for (n = 0; n < (int)size; n++)
	{
		sort[count[array[n]] - 1] = array[n];
		count[array[n]] -= 1;
	}

	for (n = 0; n < (int)size; n++)
		array[n] = sort[n];

	free(sort);
	free(count);
}
