#include "sort.h"

/**
 * counting_sort - sorts an array using count sort
 * @array: the array to sort
 * @size: the size of the array
 */

void counting_sort(int *array, size_t size)
{
	int *count_array, *sorted_array;
	int k = 0, count_size, i;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	count_size = k + 1;
	count_array = malloc(count_size * sizeof(int));
	if (count_array == NULL)
		return;
	for (i = 0; i < count_size; i++)
		count_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		count_array[array[i]] += 1;
	for (i = 1; i < count_size; i++)
		count_array[i] += count_array[i - 1];

	print_array(count_array, count_size);
	sorted_array = malloc(size * sizeof(int));
	if (sorted_array == NULL)
	{
		free(count_array);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
	{
		array[i] = sorted_array[i];
	}
	free(count_array);
	free(sorted_array);
}
