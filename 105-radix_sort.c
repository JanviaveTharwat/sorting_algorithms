#include "sort.h"

int maximum(int *array, int size);
void Rcounting_sort(int *array, size_t size, int sig, int *temp);
void radix_sort(int *array, size_t size);

/**
 * maximum - gets the maximum value
 * @array: the array
 * @size: The size
 * Return: The maximum integer
 */
int maximum(int *array, int size)
{
	int max, index;

	for (max = array[0], index = 1; index < size; index++)
	{
		if (array[index] > max)
			max = array[index];
	}

	return (max);
}

/**
 * counting_sort - Sort array using the counting sort algorithm
 * @array: the array of integers.
 * @size: The size
 * @sig: The significant digit
 * @temp: A buffer to store the sorted array
 */
void Rcounting_sort(int *array, size_t size, int sig, int *temp)
{
	int c[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t index;

	for (index = 0; index < size; index++)
		c[(array[index] / sig) % 10] += 1;

	for (index = 0; index < 10; index++)
		c[index] += c[index - 1];

	for (index = size - 1; (int)index >= 0; index--)
	{
		temp[c[(array[index] / sig) % 10] - 1] = array[index];
		c[(array[index] / sig) % 10] -= 1;
	}

	for (index = 0; index < size; index++)
		array[index] = temp[index];
}

/**
 * radix_sort - Sort an array using the radix sort algorithm.
 * @array: An array
 * @size: The size
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	max = maximum(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		Rcounting_sort(array, size, sig, temp);
		print_array(array, size);
	}

	free(temp);
}
