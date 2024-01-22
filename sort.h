#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* function prototypes for mandatory tasks */

void print_list(const listint_t *list);
void quick_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

/* function prototypes for quick sort */

void swap(int *x, int *y);
void _quicksort(int *array, int low, int high, size_t size);
size_t partition(int *array, int low, int high, size_t size);

/* function prototypes for cocktail sort algorithm */

void cocktail_sort_list(listint_t **list);
bool left_bubble_sort(listint_t **list, listint_t **current);
bool right_bubble_sort(listint_t **list, listint_t **current);

#endif
