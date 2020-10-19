#include "sort.h"

/**
 * swap - swaps two numbers
 * @num1: first number
 * @num2: second number
 */
void swap(int *num1, int *num2)
{
	int aux;

	aux = *num1;
	*num1 = *num2;
	*num2 = aux;
}

/**
 * partition - pivot and swaps elements
 * @array: array
 * @pos_init: init position
 * @right_pos: end position
 * @size: size of the array
 *
 * Return: pivot number
 */
int partition(int *array, ssize_t pos_init, ssize_t right_pos, size_t size)
{
	int pivot = array[right_pos];
	ssize_t j = pos_init, i;

	for (i = pos_init; i < right_pos; i++)
	{
		if (array[i] < pivot)
		{
			if (j != i)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}

			j++;
		}
	}

	if (right_pos != j && array[right_pos] != array[j])
	{
		swap(&array[right_pos], &array[j]);
		print_array(array, size);
	}

	return (j);
}

/**
 * quicksort - added mofe parameters to quick sorts
 * @array: array
 * @pos_init: init position
 * @right_pos: end position
 * @size: size of the array
 *
 * Return: void
 */
void quicksort(int *array, ssize_t pos_init, ssize_t right_pos, size_t size)
{
	if (pos_init < right_pos)
	{
		int pivot = partition(array, pos_init, right_pos, size);

		quicksort(array, pos_init, pivot - 1, size);
		quicksort(array, pivot + 1, right_pos, size);
	}
}

/**
 * quick_sort - main quick sort function
 * @array: array
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
