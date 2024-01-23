#ifndef SORT_H
#define SORT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

/* function prototypes for quick sort using the Lomuto partition scheme */

void swap(int *x, int *y);
void _quicksort(int *array, size_t size, int low, int high);
int lomuto_partition(int *array, size_t size, int low, int high);

/* function prototypes for cocktail sort algorithm */

void cocktail_sort_list(listint_t **list);
bool left_bubble_sort(listint_t **list, listint_t **current);
bool right_bubble_sort(listint_t **list, listint_t **current);

/* function prototypes for quick sort using the Hoare's partition scheme */

void quick_sort_hoare(int *array, size_t size);
int hoare_partition(int *array, size_t size, int low, int high);

/* function prototypes for merge sort */

void merge_sort(int *array, size_t size);
void _merge_sort(int *sub_array, int *temp_array, int left, int right);
void _merge(int *sub_array, int *temp_array, int left, int mid, int right);

/* function prototype for shell sort*/

void shell_sort(int *array, size_t size);

#endif
