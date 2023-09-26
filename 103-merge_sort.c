#include "sort.h"

/**
 * print_sort - prints the sorted data
 * @msg: message to print
 * @array: array to print
 * @from: start
 * @to: end
 */
void print_sort(char *msg, int *array, int from, int to)
{
	int i;
	char *s;

	printf("[%s]: ", msg);
	s = "";
	for (i = from; i <= to; i++)
	{
		printf("%s%d", s, array[i]);
		s = ", ";
	}
	printf("\n");
}
/**
 * _merge - implements merge algorithm
 * @array: array to sort
 * @low: first index
 * @middle: middle index
 * @high: last index
 * @buff: buffer
 */
void _merge(int *array, int low, int middle, int high, int *buff)
{
	int i, lw, mid;

	i = lw = low;
	mid = middle + 1;
	printf("Merging...\n");
	print_sort("left", array, low, middle);
	print_sort("right", array, middle + 1, high);

	while (lw <= middle && mid <= high)
	{
		if (array[lw] < array[mid])
			buff[i++] = array[lw++];
		else
			buff[i++] = array[mid++];
	}
	while (lw <= middle)
		buff[i++] = array[lw++];
	while (mid <= high)
		buff[i++] = array[mid++];
	for (i = low; i <= high; i++)
		array[i] = buff[i];
	print_sort("Done", array, low, high);
}
/**
 * aux_msort - auxiliary function for merge algorithm
 * @array: array to sort
 * @low: first index
 * @high: last index
 * @buff: buffere to store the sort elements
 */
void aux_msort(int *array, int low, int high, int *buff)
{
	int mid;

	if (low < high)
	{
		mid = (low + high - 1) / 2;
		aux_msort(array, low, mid, buff);
		aux_msort(array, mid + 1, high, buff);
		_merge(array, low, mid, high, buff);
	}
}
/**
 * merge_sort - sorts array of integers using merge sort algorithms
 * @array: array of integers
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	buff = malloc(sizeof(int) * size);
	if (!buff)
		return;
	aux_msort(array, 0, size - 1, buff);
	free(buff);
}
