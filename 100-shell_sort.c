#include "sort.h"

/**
 * shell_sort - shell sort method
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	int *arr_gap, gap, gaps, i;
	size_t i_check, prev;
	size_t sum;

	gaps = 0;
	for (sum = 1; sum <= size / 2; sum = sum * 3 + 1)
		gaps++;

	if (array && size > 1)
	{
		arr_gap = malloc(sizeof(int) * gaps);

		for (sum = 1, i = 0; i < gaps; sum = sum * 3 + 1, i++)
			arr_gap[i] = sum;

		prev = 0;
		gap = arr_gap[--i];
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
				if (i != 0)
				{
					gap = arr_gap[--i];
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
