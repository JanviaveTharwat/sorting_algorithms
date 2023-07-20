#include "sort.h"

/**
 * int_swapping - Swap two integers in an array.
 * @pra: The first integer to swap.
 * @prb: The second integer to swap.
 * Return: void
 */
void int_swapping(int *pra, int *prb)
{
	int tmp;

	tmp = *pra;
	*pra = *prb;
	*prb = tmp;
}

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * Return :void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				int_swapping(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
