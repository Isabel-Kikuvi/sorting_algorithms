#include "sort.h"

/**
 * partition - splits the array into 2 partitions
 * @array: the array to be sorted
 * @lower_bound: value at the beginig of array
 * @upper_bound: value at the end of array
 * @size: size of the array
 * Return: pivot point
 */

int partition(int *array, int lower_bound, int upper_bound, size_t size)
{
	int *pivot, i, j;

	pivot = array + upper_bound;
	for (i = j = lower_bound; j < upper_bound; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}

	return (i);
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

/**
 * quick_sort_helper - recursive function that sorts an array
 * @array: the array to be sorted
 * @lb: value at the beginig of array
 * @ub: value at the end of array
 * @size: size of the array
 */

void quick_sort_helper(int *array, int lb, int ub, size_t size)
{
	int j;

	if (lb < ub)
	{
		j = partition(array, lb, ub, size);
		quick_sort_helper(array, lb, j - 1, size);
		quick_sort_helper(array, j + 1, ub, size);
	}
}

/**
 * quick_sort - sorts an array using quick sort
 * @array: the array to be sorted
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
