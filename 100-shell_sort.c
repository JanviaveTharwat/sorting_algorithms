#include "sort.h"

/**
 * int_swapping - Swap two integers in an array.
 * @pra: The first integer to swap.
 * @prb: The second integer to swap.
 */
void int_swapping(int *pra, int *prb)
{
	int tmp;

	tmp = *pra;
	*pra = *prb;
	*prb = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending order
 * @array: An array of integers
 * @size: The size of the array
 * Return : void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, a, a;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (a = gap; a < size; a++)
		{
			b = a;
			while (b >= gap && array[b - gap] > array[b])
			{
				int_swapping(array + b, array + (b - gap));
				b -= gap;
			}
		}
		print_array(array, size);
	}
}
