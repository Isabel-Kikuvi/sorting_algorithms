#include "sort.h"

/**
 * hoare_partition - function to partition an array
 * @array: the array to partition
 * @size: size of the array
 * @lb: first element in array
 * @ub: last element in array
 * Return: partition index
 */

int hoare_partition(int *array, size_t size, int lb, int ub)
{
	int pivot, i, j;

	pivot = array[ub];
	i = lb - 1;
	j = ub + 1;

	while (i < j)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
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
 * hoare_helper - recursive function to sort an array
 * @array: the array to sort
 * @size: size of array
 * @lb: first element in array
 * @ub: last element in array
 */

void hoare_helper(int *array, size_t size, int lb, int ub)
{
	int j;

	if (ub > lb)
	{
		j = hoare_partition(array, size, lb, ub);
		hoare_helper(array, size, lb, j - 1);
		hoare_helper(array, size, j, ub);
	}
}

/**
 * quick_sort_hoare - sorts an array using quick sort-hoare
 * @array: the array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_helper(array, size, 0, size - 1);
}
