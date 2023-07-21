#include "sort.h"

void swap_integers(int *a, int *b);
int partition(int *array, size_t size, int left, int right);
void lomuto(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_integers - Swap two integers
 * @f: The first
 * @s: The second
 */
void swap_integers(int *f, int *s)
{
	int temp;

	temp = *f;
	*f = *s;
	*s = temp;
}

/**
 * partition - Order apartaion of an array
 * @array: The array
 * @size: The size
 * @start: The starting index
 * @end: The ending index
 *
 * Return: The final partition index.
 */
int partition(int *array, size_t size, int start, int end)
{
	int *pivot, up, down;

	pivot = array + end;
	for (up = down = start; down < end; down++)
	{
		if (array[down] < *pivot)
		{
			if (up < down)
			{
				swap_integers(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *pivot)
	{
		swap_integers(array + up, pivot);
		print_array(array, size);
	}

	return (up);
}


/**
 * quick_sort - sort an array using the quicksort algorithm.
 * @array: the array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto(array, size, 0, size - 1);
}
/**
 * lomuto - Implement the quicksort algorithm through recursion.
 * @array: An array
 * @size: The size
 * @start: The starting index of the partition
 * @end: The ending index of the partition
 */
void lomuto(int *array, size_t size, int start, int end)
{
	int part;

	if (end - start > 0)
	{
		part = partition(array, size, start, end);
		lomuto(array, size, start, part - 1);
		lomuto(array, size, part + 1, end);
	}
}
