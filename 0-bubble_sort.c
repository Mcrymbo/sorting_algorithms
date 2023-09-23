#include "sort.h"
/**
 * swap - swaps integer
 * @a: first integer
 * @b: second integer
 * Return: no return
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
/**
 * bubble_sort - sorts an array in ascending order
 * @array: array of integers
 * @size: size of array to sort
 * Return: no return
 */
void bubble_sort(int *array, size_t size)
{
	int swapped = 0;
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}
