#include "sort.h"

/**
 * insertion_sort - sorts a doubly linked list using insertion algorithm
 * @list: doubly linked list
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp;

	if (!list || !(*list) || !(*list)->next)
		return;

	curr = *list;
	while (curr != NULL)
	{
		while (curr->next && (curr->n > curr->next->n))
		{
			temp = curr->next;
			curr->next = temp->next;
			temp->prev = curr->prev;

			if (curr->prev != NULL)
				curr->prev->next = temp;
			if (temp->next != NULL)
				temp->next->prev = curr;
			curr->prev = temp;
			temp->next = curr;
			if (temp->prev)
				curr = temp->prev;
			else
				*list = temp;
			print_list(*list);
		}
		curr = curr->next;
	}
}
