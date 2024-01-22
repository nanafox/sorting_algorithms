#include "sort.h"

/**
 * quick_sort - Sorts an array of integers using the Quick Sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_quicksort(array, 0, size - 1, size);
}

/**
 * _quicksort - recursive function to sort the array using the quick sort
 * algorithm
 *
 * @array: array to be sorted
 * @low: first element of array
 * @high: last element of array
 * @size: size of array
 * Return: void
 */
void _quicksort(int *array, int low, int high, size_t size)
{
	size_t pivot_index;

	if (low < 0 || low >= high)
	{
		return;
	}

	pivot_index = partition(array, low, high, size);

	_quicksort(array, low, pivot_index - 1, size);
	_quicksort(array, pivot_index + 1, high, size);
}

/**
 * partition - divides the array into two partitions using the Lomuto scheme
 *
 * @array: array to be sorted
 * @low: first element of array
 * @high: last element of array
 * @size: size of array
 *
 * Return: the pivot index
 */
size_t partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int pivot_index = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			pivot_index++;
			if (pivot_index != j)
			{
				swap(&array[pivot_index], &array[j]);
				print_array(array, size);
			}
		}
	}
	pivot_index++;
	if (array[pivot_index] > pivot)
	{
		swap(&array[pivot_index], &array[high]);
		print_array(array, size);
	}

	return (pivot_index);
}

/**
 * swap - swaps two element in an array
 * @x: the first value
 * @y: the second value
 */
void swap(int *x, int *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}
