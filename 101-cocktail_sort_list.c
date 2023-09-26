#include "sort.h"

/**
 * swap - swaps elements of the doubly linked list
 * @h1: head 1
 * @h2: head 2
 * @n: 0 for increase and 1 for decrease
 */
void swap(listint_t **h1, listint_t **h2, int n)
{
	listint_t *curr, *temp;

	curr = *h1;
	temp = *h2;
	curr->next = temp->next;
	temp->prev = curr->prev;

	if (temp->next != NULL)
		temp->next->prev = curr;
	if (curr->prev)
		curr->prev->next = temp;
	curr->prev = temp;
	temp->next = curr;
	if (n == 0)
		*h1 = temp;
	else
		*h2 = curr;
}
/**
 * sort_inc - moves larger nubers to the end of the list
 * @h: pointer to larger number
 * @lim: limit of the list
 * @list: list of integers to sort
 */
void sort_inc(listint_t **h, listint_t **lim, listint_t **list)
{
	listint_t *temp = *h;

	while (temp != *lim && temp->next != *lim)
	{
		if (temp->n > temp->next->n)
		{
			swap(&temp, &(temp->next), 0);
			if (temp->prev == NULL)
				*list = temp;
			print_list(*list);
		}
		temp = temp->next;
	}
	*lim = temp;
	*h = temp;
}
/**
 * sort_dec - moves smaller numbers to start of the list
 *
 * @h: pointer to larger number
 * @lim: limit of the list
 * @list: list of integers to sort
 */
void sort_dec(listint_t **h, listint_t **lim, listint_t **list)
{
	listint_t *temp = *h;

	while (temp != *lim && temp->prev != *lim)
	{
		if (temp->n < temp->prev->n)
		{
			swap(&(temp->prev), &temp, 1);
			if (temp->prev->prev == NULL)
				*list = temp->prev;
			print_list(*list);
		}
		temp = temp->prev;
	}
	*lim = temp;
	*h = temp;
}
/**
 * cocktail_sort_list - sorts a doubly linked list
 * @list: head of linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *lim1, *lim2, *h;

	if (list == NULL || *list == NULL)
		return;
	lim1 = lim2 = NULL;
	h = *list;
	do {
		sort_inc(&h, &lim1, list);
		sort_dec(&h, &lim2, list);
	} while (lim1 != lim2);
}
