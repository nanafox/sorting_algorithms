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

	_quicksort(array, size, 0, size - 1);
}

/**
 * _quicksort - recursive function to sort the array using the quick sort
 * algorithm
 *
 * @array: array to be sorted
 * @low: first element of array
 * @high: last element of array
 * @size: size of array
 */
void _quicksort(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (low < 0 || low >= high)
		return;

	pivot_index = lomuto_partition(array, size, low, high);

	_quicksort(array, size, low, pivot_index - 1);
	_quicksort(array, size, pivot_index + 1, high);
}

/**
 * lomuto_partition - divides the array into two partitions using the
 * Lomuto partition scheme
 *
 * @array: array to be sorted
 * @low: first element of array
 * @high: last element of array
 * @size: size of array
 *
 * Return: the pivot index
 */
int lomuto_partition(int *array, size_t size, int low, int high)
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
	if (!x || !y)
		return;

	if (*x != *y)
	{
		*x ^= *y;
		*y ^= *x;
		*x ^= *y;
	}
}
