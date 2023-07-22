#include "sort.h"
void merge_sub(int *subarr, int *temp, size_t front, size_t mid,
		size_t back);
void recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_sort - Sort an array using the merge sort algorithm.
 * @array: An array
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	recursive(array, temp, 0, size);

	free(temp);
}
/**
 * recursive - Implement the merge sort algorithm through recursion.
 * @arr: A subarray
 * @temp: A temp to store the sorted result
 * @front: The front index
 * @back: The back index
 */
void recursive(int *arr, int *temp, size_t front, size_t back)
{
	size_t middle;

	if (back - front > 1)
	{
		middle = front + (back - front) / 2;
		recursive(arr, temp, front, middle);
		recursive(arr, temp, middle, back);
		merge_sub(arr, temp, front, middle, back);
	}
}

/**
 * merge_sub - Sort a subarray
 * @arr: A subarray
 * @temp: A temp to store
 * @front: The front index
 * @mid: The middle index
 * @back: The back index
 */
void merge_sub(int *arr, int *temp, size_t front, size_t mid,
		size_t back)
{
	size_t index, j, m = 0;

	printf("Merging...\n[left]: ");
	print_array(arr + front, mid - front);

	printf("[right]: ");
	print_array(arr + mid, back - mid);

	for (index = front, j = mid; index < mid && j < back; m++)
		temp[m] = (arr[m] < arr[j]) ? arr[index++] : arr[j++];
	for (; index < mid; index++)
		temp[m++] = arr[index];
	for (; j < back; j++)
		temp[m++] = arr[j];
	for (index = front, m = 0; index < back; index++)
		arr[index] = temp[m++];

	printf("[Done]: ");
	print_array(arr + front, back - front);
}
