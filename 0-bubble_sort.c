#include "sort.h"

/**
 * bubble_sort - sorts an array in ascending order
 * @array: array of integers
 * @size: size of array to sort
 * Return: no return
 */
void bubble_sort(int *array, size_t size)
{
	int temp, swapped = 0;
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
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
		if (swapped == 0)
			break;
	}
}
