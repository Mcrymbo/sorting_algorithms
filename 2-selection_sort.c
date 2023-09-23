#include "sort.h"

/**
 * swap - swaps integers
 * @a: first element i array
 * @b: second array
 * Return: no return
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sorts array using selction sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			swap(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
