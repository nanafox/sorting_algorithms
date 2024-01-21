#include "sort.h"

void quicksort_recursive(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void swap(int *array, int a, int b);

/**
 * quick_sort - Sorts an array of integers using Quick Sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}
/**
 * quicksort_recursive - recursive function to sort the array
 *
 * @array: array to be sorted
 * @low: first element of array
 * @high: last element of array
 * @size: size of array
 * Return: void
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		quicksort_recursive(array, low, pivot_index - 1, size);
		quicksort_recursive(array, pivot_index + 1, high, size);
	}
}
/**
 * partition - carries out the partition exchange Sort algorithm
 *
 * @array: array to be sorted
 * @low: first element of array
 * @high: last element of array
 * @size: size of array
 * Return: returns pivot number
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	i++;
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	print_array(array, size);

	return (i);
}
/**
 * swap - swaps elements of the array
 *
 * @array: array to be sorted
 * @a: element to be swapped
 * @b: element to be swapped
 */
void swap(int *array, int a, int b)
{
	int temp;

	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

