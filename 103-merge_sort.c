#include "sort.h"

/**
 * merge_sort - Sort an array of integers in ascending order
 * using the merge sort algorithm.
 * @array: A pointer to the integer array to be sorted.
 * @size: The size of the array.
 *
 * Description: This function first checks if the array is NULL or if the size
 * is less than 2. If either condition is met, the function returns without
 * performing any sorting. The function then allocates memory for a temporary
 * array. If this memory allocation fails, the function will return.
 * Otherwise, it calls the helper function, `_merge_sort`, to sort the array,
 * then frees the temporary array before returning.
 */
void merge_sort(int *array, size_t size)
{
	int *temp_array;

	if (array == NULL || size < 2)
		return;

	temp_array = malloc(sizeof(int) * size);
	if (temp_array == NULL)
		return;

	_merge_sort(array, temp_array, 0, size);

	free(temp_array);
}

/**
 * _merge_sort - Executes the merge sort algorithm via recursion.
 * @sub_array: A pointer to the segment of the array that needs sorting.
 * @temp_array: A pointer to a temporary array that holds the interim sorted
 * result.
 * @left: The start index of the segment in the sub array.
 * @right: The end index of the segment in the sub array.
 *
 * Description: This function carries out the merge sort algorithm in a
 * recursive manner. It first checks if the length of the segment is less than
 * or equal to 1. If this is the case, it assumes the segment is already sorted
 * and returns immediately. Otherwise, it calculates the middle point of the
 * segment, then recursively sorts the left and right portions of the segment.
 * After sorting, it merges the two sub arrays using the `_merge` function.
 */
void _merge_sort(int *sub_array, int *temp_array, int left, int right)
{
	int midpoint;

	if (right - left <= 1)
		return;

	midpoint = left + (right - left) / 2;
	_merge_sort(sub_array, temp_array, left, midpoint);
	_merge_sort(sub_array, temp_array, midpoint, right);
	_merge(sub_array, temp_array, left, midpoint, right);
}

/**
 * _merge - Fuses two sub arrays into one ordered array.
 * @sub_array: A pointer to the array containing the sub arrays.
 * @temp_array: A pointer to a temporary array.
 * @left: The starting index of the first sub array.
 * @midpoint: The starting index of the second sub array.
 * @right: The ending index of the second sub array.
 *
 * Description: This function fuses two sub arrays into a single ordered array.
 * It first initializes two indices, `i` and `j`, to the starting points of the
 * first and second sub arrays respectively. It then compares the elements at
 * these indices in the original array. The smaller element is transferred into
 * the temporary array and the corresponding index (`i` or `j`) is incremented.
 * If the elements are equal, the element from the first sub array is
 * preferred. This process continues until all elements in the sub arrays have
 * been fused into the temporary array. Finally, the ordered elements in the
 * temporary array are copied back into the original array. The function also
 * prints the merging process, including the left and right sub arrays being
 * merged and the final merged array.
 */
void _merge(int *sub_array, int *temp_array, int left, int midpoint, int right)
{
	int i, j, k;

	printf("Merging...\n");

	printf("[left]: ");
	print_array(&sub_array[left], midpoint - left);

	printf("[right]: ");
	print_array(&sub_array[midpoint], right - midpoint);

	i = left;
	j = midpoint;
	k = 0;
	while (i < midpoint && j < right)
	{
		if (sub_array[i] < sub_array[j])
			temp_array[k++] = sub_array[i++];
		else
			temp_array[k++] = sub_array[j++];
	}

	while (i < midpoint)
		temp_array[k++] = sub_array[i++];
	while (j < right)
		temp_array[k++] = sub_array[j++];

	for (i = left, k = 0; i < right; i++)
		sub_array[i] = temp_array[k++];

	printf("[Done]: ");
	print_array(&sub_array[left], right - left);
}
