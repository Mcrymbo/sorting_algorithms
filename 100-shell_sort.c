#include "sort.h"


/**
 * shell_sort - sorts array using shell sort algorithm
 * @array: array to sort
 * @size: size of integer
 * Return: no return
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int temp;

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
		if (gap == 1)
			break;
		gap /= 3;
	}
}
