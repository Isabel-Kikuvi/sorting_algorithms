#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using bubblesort
 * @array: the array to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, flag;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
			}
			print_list(array, size);
		}
		if (flag == 0)
			break;
	}

}