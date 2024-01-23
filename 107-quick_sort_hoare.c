#include "sort.h"
#include <stdbool.h>

/**
 * quick_sort_hoare - Sorts an array of integers using the Quick Sort Algorithm
 *
 * @array: an array of integers
 * @size: the size of the array
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_quicksort(array, size, 0, size - 1);
}

/**
 * _quicksort - Sorts an array of integers using the Quick Sort algorithm
 *              This is the actual implementation of the algorithm.
 * @array: an array of integers
 * @size: the size of the array
 * @low: lower bound index
 * @high: higher bound index
 */
void _quicksort(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (low >= 0 && high >= 0 && low < high)
	{
		pivot_index = hoare_partition(array, size, low, high);
		_quicksort(array, size, low, pivot_index);
		_quicksort(array, size, pivot_index + 1, high);
	}
}

/**
 * hoare_partition - Divides an array into two partitions using the
 * Hoare partition scheme
 * @array: an array of integers
 * @size: the size of the array
 * @low: lower bound index
 * @high: higher bound index
 *
 * Return: The pivot index
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot_index, j, pivot;
	bool partitioning = true;

	pivot = array[high];
	pivot_index = low - 1;
	j = high + 1;

	while (partitioning)
	{
		do {
			pivot_index++;
		} while (array[pivot_index] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (pivot_index <= j)
		{
			if (pivot_index != j)
			{
				swap(&array[pivot_index], &array[j]);
				print_array(array, size);
			}
		}
		else
			partitioning = false;
	}

	return (j);
}

/**
 * swap - swaps two element in an array
 * @x: the first value
 * @y: the second value
 */
void swap(int *x, int *y)
{
	if (!x || !y)
		return;

	if (*x != *y)
	{
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}
