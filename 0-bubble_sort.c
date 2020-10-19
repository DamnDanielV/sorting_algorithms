#include "sort.h"
/**
 * bubble_sort - bubble sort algorithm
 * @array: array of integers
 * @size: size of the array
 * return: nothing void
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int aux;

	if (!array || size == 1 || !size)
		return;
	for (j = size - 1; j > 0; j--)
	{
		for (i = 0; i < j; i++)
		{
			if (array[i] > array[i + 1])
			{
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
				print_array(array, size);
			}
		}
	}
}
