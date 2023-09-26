#include "sort.h"

/**
 * radix_sort - sorts array using radix algorithm
 * @array: array of index
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	size_t i, j;
	int n = 10, flag = 1;

	if (!array || size == 1)
		return;
	while (flag)
	{
		flag = 0;
		for (i = j = 1; i < size; i++, j++)
		{
			if ((array[i - 1] % (n * 10)) / ((n * 10) / 10) > 0)
				flag = 1;
			if (((array[i - 1] % n) / (n / 10)) > ((array[i] % n) / (n / 10)))
			{
				array[i - 1] = array[i - 1] + array[i];
				array[i] = array[i - 1] - array[i];
				array[i - 1] = array[i - 1] - array[i];
				if ((i - 1) > 0)
					i = i - 2;
			}
		}
		print_array(array, size);
		n = n * 10;
	}
}
