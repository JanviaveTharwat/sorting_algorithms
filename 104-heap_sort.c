#include "sort.h"

void int_swapping(int *pta, int *ptb);
void max_heap(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * int_swapping - Swap two integers in an array
 * @pta: The first integer to swap
 * @ptb: The second integer to swap
 * Return :void
 */
void int_swapping(int *pta, int *ptb)
{
	int tmp;

	tmp = *pta;
	*pta = *ptb;
	*ptb = tmp;
}

/**
 * max_heap - Turn a binary tree into a complete binary heap
 * @array: An array of integers representing a binary tree
 * @size: The size of the array/tree
 * @base: The index of the base row of the tree
 * @root: The root node of the binary tree
 * Return :void
 */
void max_heap(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		int_swapping(array + root, array + large);
		print_array(array, size);
		max_heap(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 * Return : void
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heap(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		int_swapping(array, array + i);
		print_array(array, size);
		max_heap(array, size, i, 0);
	}
}
