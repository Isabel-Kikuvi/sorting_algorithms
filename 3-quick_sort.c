#include "sort.h"

int partition(int *array, int lower_bound, int upper_bound, size_t size)
{
	int pivot, start, end;

	pivot = array[lower_bound];
	start = lower_bound;
	end = upper_bound;

	while (start < end)
	{
		while (array[start] <= pivot)
			start++;
		while (array[end] > pivot)
			end --;
		if (start < end)
		{
			swap(&array[start], &array[end]);
		}
	}
	swap(&array[lower_bound], &array[end]);
	print_array(array, size);


	return (end);
}

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
	
void quick_sort_helper(int *array, int lower_bound, int upper_bound, size_t size)
{
	int j;

	if (lower_bound < upper_bound)
	{
		j = partition(array, lower_bound, upper_bound, size);
		quick_sort_helper(array, lower_bound, j - 1, size);
		quick_sort_helper(array, j + 1, upper_bound, size);
	}
}


void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
