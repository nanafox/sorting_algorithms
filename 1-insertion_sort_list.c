#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * using the insertion sort algorithm.
 * @list: A pointer to the head of a doubly-linked list of integers.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *left, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return; /* skip empty lists  or one-element lists */

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		left = current->prev;
		while (left != NULL && current->n < left->n)
		{
			/* Swap nodes */
			current->prev = left->prev;
			if (left->prev != NULL)
				left->prev->next = current;
			else
				*list = current;

			left->next = current->next;
			if (current->next != NULL)
				current->next->prev = left;

			current->next = left;
			left->prev = current;

			print_list((const listint_t *)*list);

			left = current->prev;
		}
		current = next;
	}
}
