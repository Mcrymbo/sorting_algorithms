#include "sort.h"

/**
 * print_data - prints the modified array
 * @array: input array
 * @a: first index
 * @b: last index
 */
void print_data(int *array, int a, int b)
{
	char *s;

	for (s = ""; a < b; a++)
	{
		printf("%s%d", s, array[a]);
		s = ", ";
	}
	printf("\n");
}
/**
 * sort_up - sorting array in UP mode
 * @array: input array
 * @f1: first index
 * @f2: second index
 */
void sort_up(int *array, int f1, int f2)
{
	int i, j;
	int max;

	for (i = f1; i < f2; i++)
	{
		max = i;
		for (j = i + 1; j < f2; j++)
		{
			if (array[max] > array[j])
				max = j;
		}
		if (max != i)
		{
			array[i] = array[i] + array[max];
			array[max] = array[i] - array[max];
			array[i] = array[i] - array[max];
		}
	}
}
/**
 * sort_down - sorting using DOWN mode
 *
 * @array: array of integers
 * @f1: first index
 * @f2: last index
 */
void sort_down(int *array, int f1, int f2)
{
	int i, j;
	int max;

	for (i = f1; i < f2; i++)
	{
		max = i;
		for (j = i + 1; j < f2; j++)
		{
			if (array[max] < array[j])
				max = j;
		}
		if (max != i)
		{
			array[i] = array[i] + array[max];
			array[max] = array[i] - array[max];
			array[i] = array[i] - array[max];
		}
	}
}
/**
 * recurse - aux function that executes bitonic sort
 * @array: array of integers
 * @f1: first index
 * @f2: last integers
 * @bool: UP or DOWN
 * @size: array size
 */
void recurse(int *array, int f1, int f2, int bool, size_t size)
{
	char *opt;

	if (f2 - f1 < 2)
		return;
	opt = (bool == 0) ? "UP" : "DOWN";
	printf("Merging [%d/%ld] (%s):\n", f2 - f1, size, opt);
	print_data(array, f1, f2);
	if (f2 - f1 == 2)
		return;
	recurse(array, f1, (f2 + f1) / 2, 0, size);
	sort_up(array, f1, (f2 + f1) / 2);
	printf("Result [%d/%ld] (%s):\n", ((f2 + f1) / 2) - f1, size, "UP");
	print_data(array, f1, (f2 + f1) / 2);

	recurse(array, (f2 + f1) / 2, f2, 1, size);
	sort_down(array, (f2 + f1) / 2, f2);
	printf("Result [%d/%ld] (%s):\n", f2 - ((f2 + f1) / 2), size, "DOWN");
	print_data(array, (f2 + f1) / 2, f2);
}


/**
 * bitonic_sort - sorts array using bitonic sort algorithm
 * @array: array of integers
 * @size: array size
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recurse(array, 0, size, 0, size);
	sort_up(array, 0, size);
	printf("Result [%ld/%ld] (%s):\n", size, size, "UP");
	print_data(array, 0, size);
}
