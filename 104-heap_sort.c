#include "sort.h"

/**
 * swap - swaps numbers in an array
 * @array: array of integers
 * @a: first index
 * @b: second index
 */
void swap(int *array, int a, int b)
{
	array[a] = array[a] + array[b];
	array[b] = array[a] - array[b];
	array[a] = array[a] - array[b];
}
/**
 * heap_tree - building recursion tree recursively
 * @array: int array
 * @idx: index
 * @size: array size
 * @lim: limit of the array
 */
void heap_tree(int *array, int idx, size_t size, int lim)
{
	int i, big;

	i = idx * 2;
	if (i + 2 < lim)
	{
		heap_tree(array, i + 1, size, lim);
		heap_tree(array, i + 2, size, lim);
	}
	if (i + 1 >= lim)
		return;
	if (i + 2 < lim)
		big = (array[i + 1] > array[i + 2]) ? (i + 1) : (i + 2);
	else
		big = i + 1;
	if (array[idx] < array[big])
	{
		swap(array, idx, big);
		print_array(array, size);
		heap_tree(array, big, size, lim);
	}
}
/**
 * heap_sort - sorts array using heap algorithm
 * @array: input array
 * @size: array size
 * Return: no return
 */
void heap_sort(int *array, size_t size)
{
	int i;
	size_t lim;

	if (!array || size == 0)
		return;
	lim = size;
	i = 0;
	while (lim > 1)
	{
		heap_tree(array, i, size, lim);
		if (array[i] >= array[lim -1])
		{
			swap(array, i, lim - 1);
			print_array(array, size);
		}
		lim--;
	}
}
