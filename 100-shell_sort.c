#include "sort.h"

/**
 * shell_sort - sorts an array using shell sort
 * @array: the array to be sorted
 * @size: the size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (; gap >= 1; gap /= 3)
		{
			for (j = gap; j < size; j++)
			{
				i = j;
				while (i >= gap && array[i - gap] > array[i])
				{
					swap(array + i, array + (i - gap));
					i -= gap;
				}
			}
		print_array(array, size);
		}
	}
}

/**
 * swap - swaps two ints
 * @a: first int
 * @b: second int
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
