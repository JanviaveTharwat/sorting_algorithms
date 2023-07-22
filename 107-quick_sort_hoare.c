/*
 * File: 107-quick_sort_hoare.c
 * Auth: Brennan D Baraban
 */

#include "sort.h"

void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);
void swap(int *a, int *b);
int hpartition(int *array, size_t size, int left, int right);


/**
 * hpartition - partitoning according to the hoare partition scheme
 * @array: The array
 * @size: The size
 * @left: The starting index
 * @right: The ending index
 *
 * Return: The final partition index.
 */
int hpartition(int *array, size_t size, int left, int right)
{
	int pivot, up, down;

	pivot = array[right];
	for (up = left - 1, down = right + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < pivot);
		do {
			down--;
		} while (array[down] > pivot);

		if (up < down)
		{
			swap(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}


/**
 * quick_sort_hoare - Sort an array of integers using the quicksort algorithm.
 * @array: An array
 * @size: The size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}

/**
 * hoare_sort - Implement the quicksort algorithm by recursion
 * @array: An array
 * @size: The size
 * @left: The starting index
 * @right: The ending index
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int temp;

	if (right - left > 0)
	{
		temp = hpartition(array, size, left, right);
		hoare_sort(array, size, left, temp - 1);
		hoare_sort(array, size, temp, right);
	}
}

/**
 * swap - Swap two integers
 * @a: The first
 * @b: The second
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
