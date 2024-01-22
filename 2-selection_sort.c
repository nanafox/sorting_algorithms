#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, cur_min;
	bool min_found; /* tracks whether a lesser value is found */

	/* there's no need to perform sorting on empty or one-element arrays */
	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		cur_min = i;
		min_found = false;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[cur_min])
			{
				cur_min = j;
				min_found = true;
			}
		}

		if (min_found)
		{
			/* swap the elements */
			array[i] ^= array[cur_min];
			array[cur_min] ^= array[i];
			array[i] ^= array[cur_min];

			/* print the current view of the array */
			print_array(array, size);
		}
	}
}
