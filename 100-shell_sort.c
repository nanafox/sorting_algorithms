#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using the Shell
 * sort algorithm
 * @array: A pointer to the integer array to be sorted
 * @size: The size of the array
 *
 * Description: This function sorts an array of integers in ascending order
 * using the Shell sort algorithm. It first generates the initial interval
 * using the Knuth sequence (h = 3 * h + 1). Starting with the largest interval
 * and reducing, it sorts elements at interval h. It does this by iterating
 * over the array, and for each element, it repeatedly swaps it with the
 * element h spaces to its left if the current element is smaller, until the
 * element is in its correct position. After sorting all elements at interval
 * h, it reduces the interval and repeats the process until the interval is 0.
 * After each pass, it prints the array using the print_array function.
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, h;
	int temp;

	/* Generate the initial interval (Knuth sequence) */
	for (h = 1; h < size; h = 3 * h + 1)
		;

	/* Start with the largest interval and reduce */
	for (h = (h - 1) / 3; h > 0; h = (h - 1) / 3)
	{
		for (i = h; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= h && array[j - h] > temp)
			{
				array[j] = array[j - h];
				j -= h;
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
