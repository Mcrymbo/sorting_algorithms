#include "sort.h"

/**
 * swap - swaps array
 *
 * @start: first element
 * @end: end element of the array
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - partitions the array for sorting
 * @array: array to sort
 * @lb: lower bound
 * @ub: upper boung
 */
int partition(int *array, int lb, int ub, size_t size)
{
	int pivot, start, end;

	pivot = array[lb];
	start = lb;
	end = ub;
	while (start < end)
	{
		while (array[start] <= pivot)
			start++;
		while (array[end] > pivot)
			end--;
		if (start < end)
		{
			swap(&array[start], &array[end]);
			print_array(array, size);
		}
	}
	swap(&array[lb], &array[end]);
	print_array(array, size);
	return (end);
}

/**
 * quick_sort - invoks the sorting algorithm
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sorting(array, 0, size - 1, size);
}

/**
 * sort - sorts array using quick sort algorithm
 * @arrray: array of integers to sort
 * @lower: size of array
 * @upper: no return
 */
void sorting(int *array, int lower, int upper, size_t size)
{
	int loc;

	if (lower < upper)
	{
		loc = partition(array, lower, upper, size);
		sorting(array, lower, loc - 1, size);
		sorting(array, loc + 1, upper, size);
	}
}
