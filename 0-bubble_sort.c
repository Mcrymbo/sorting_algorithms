#include "sort.h"


/**
 * bubble_sort - sorts an array in ascending order
 *
 *
 * @array: array of integers
 * @size: size of array to sort
 * Return: no return
 */
void bubble_sort(int *array, size_t size)
{
	int swapped, temp;
	size_t i, j;

	for (i = size, swapped = 1; i > 0 && swapped; i--)
	{
		swapped = 0;
		for (j = 0; (j + 1) < i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swapped = 1;
			}
		}
	}
}
