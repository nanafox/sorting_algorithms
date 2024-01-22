#include "sort.h"

/**
 * cocktail_sort_list - sorts a list of integers using the Cocktail Sort
 * Algorithm
 *
 * @list: a pointer to a doubly linked list of integers
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	bool swapped;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;

	do {
		current = *list;

		/* First pass: left to right */
		swapped = left_bubble_sort(list, &current);
		if (!swapped)
			break;

		/* Second pass: right to left */
		swapped = right_bubble_sort(list, &current);
		if (!swapped)
			break;

	} while (swapped);
}

/**
 * left_bubble_sort - performs bubbles sort from left to right
 *
 * @list: a pointer to a doubly linked list of integers
 * @current: the current position in the linked list (start of the linked list)
 *
 * Return: true when a swap occur, false otherwise
 */
bool left_bubble_sort(listint_t **list, listint_t **current)
{
	listint_t *next;
	bool swapped = false;

	while ((*current)->next != NULL)
	{
		next = (*current)->next;
		if ((*current)->n > next->n)
		{
			/* swap nodes */
			if ((*current)->prev != NULL)
				(*current)->prev->next = next;
			else
				*list = next; /* insert at the beginning of the list */

			if (next->next != NULL)
				next->next->prev = *current;

			(*current)->next = next->next;
			next->prev = (*current)->prev;
			(*current)->prev = next;
			next->next = (*current);

			swapped = true;
			print_list((const listint_t *)*list);
		}
		else
			*current = (*current)->next;
	}

	return (swapped);
}

/**
 * right_bubble_sort - performs bubbles sort from right to left
 *
 * @list: a pointer to a doubly linked list of integers
 * @current: the current position in the linked list (end of the linked list)
 *
 * Return: true when a swap occur, false otherwise
 */
bool right_bubble_sort(listint_t **list, listint_t **current)
{
	listint_t *next;
	bool swapped = false;

	while ((*current)->prev != NULL)
	{
		next = (*current)->prev;
		if ((*current)->n < next->n)
		{
			/* swap nodes */
			if (next->prev != NULL)
				next->prev->next = *current;
			else
				*list = *current; /* insert at the beginning of the list */

			if ((*current)->next != NULL)
				(*current)->next->prev = next;

			next->next = (*current)->next;
			(*current)->prev = next->prev;
			next->prev = *current;
			(*current)->next = next;

			swapped = true;
			print_list((const listint_t *)*list);
		}
		else
			*current = (*current)->prev;
	}

	return (swapped);
}
