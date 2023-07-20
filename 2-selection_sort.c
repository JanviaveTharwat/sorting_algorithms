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
 * selection_sort - Sort an array of integers in ascending order
 * @array: An array of integers
 * @size: The size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		min = array + a;
		for (b = a + 1; b < size; b++)
			min = (array[b] < *min) ? (array + b) : min;

		if ((array + a) != min)
		{
			int_swapping(array + a, min);
			print_array(array, size);
		}
	}
}
