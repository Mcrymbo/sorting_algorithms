#include "sort.h"

/**
 * swap - swaps array
 *
 * @a: first element
 * @b: end element of the array
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition_hoare - partitions the array for sorting
 * @array: array to sort
 * @lb: lower bound
 * @ub: upper boung
 * @size: array size
 * Return: new end bound
 */
int partition_hoare(int *array, int lb, int ub, size_t size)
{
	int start, end, pivot, temp;

	pivot = array[lb];
	start = lb - 1;
	end = ub + 1;

	while (1)
	{
		do {
			start++;
		} while (array[start] < pivot);
		do {
			end--;
		} while (array[end] > pivot);

		if (start >= end)
			return (end);
		temp = array[start];
		array[start] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	return (-1);
}

/**
 * quick_sort_hoare - invoks the sorting algorithm
 * @array: array of integers
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sorting_hoare(array, 0, size - 1, size);
}

/**
 * sorting_hoare - sorts array using quick sort algorithm
 * @array: array of integers to sort
 * @lower: size of array
 * @upper: no return
 * @size: array size
 */
void sorting_hoare(int *array, int lower, int upper, size_t size)
{
	int loc;

	if (lower < upper)
	{
		loc = partition_hoare(array, lower, upper, size);
		sorting_hoare(array, lower, loc, size);
		sorting_hoare(array, loc + 1, upper, size);
	}
}
