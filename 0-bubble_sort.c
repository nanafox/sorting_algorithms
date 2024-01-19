#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers using Bubble sort algorithm
 *
 * @array: array to be sorted
 * @size: size of array
 */
 void bubble_sort(int *array, size_t size)
 {
	size_t i, j;
	int swapped, temp;
	
	if (!array || size < 2)
        return;
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			temp = array[j];
			array[j] = array[j+1];
			array[j+1] = temp;
			swapped = 1;
			print_array(array, size);
		}
		if (swapped == 0)
			break;
	}
 }
