#include "sort.h"

/**
 * shell_sort - shell sort method
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int gap;
	size_t i_check, prev;

	if (array && size > 1)
	{
		for (gap = 1; gap * 3 + 1 < (int)size; gap = gap * 3 + 1)
			;
		prev = 0;
		i_check = prev + gap;

		while (i_check < size)
		{

			if (array[i_check] < array[prev])
				swap_s(i_check, prev, gap, array);
			prev++;
			i_check++;

			if (i_check >= size)
			{
				print_array(array, size);
				if (gap > 1)
				{
					gap = (gap - 1) / 3;
					prev = 0;
					i_check = prev + gap;
				}
			}
		}
	}
}
/**
 * swap_s - swap number based on gap
 * @i_check: index of number to be i_checked
 * @prev: prev number in the array
 * @gap: gap to rotate prev and i_check
 * @i_arr: array ti reference to index
 */
void swap_s(int i_check, int prev, int gap, int *i_arr)
{
	int temp;

	while (prev >= 0 && i_arr[i_check] < i_arr[prev])
	{
		temp = i_arr[prev];

		i_arr[prev] = i_arr[i_check];

		i_arr[i_check] = temp;

		i_check -= gap;
		prev -= gap;
	}
}
