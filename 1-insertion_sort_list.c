#include "sort.h"
/**
 * insertion_sort_list - sorts a double linkedlist using insertion sort
 * @list: list to be sorted
 * return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *n_next, *n_prev;

	if (list && *list)
	{
		temp = (*list)->next;
		n_prev = temp->prev;
		n_next = temp->next;

		while (temp)
		{
			if (temp->n < n_prev->n)
			{
				while (n_prev && temp->n < n_prev->n)
				{
					if (n_next)
						n_next->prev = n_prev;

					temp->next = n_prev;
					temp->prev = n_prev->prev;

					if (n_prev->prev)
						(n_prev->prev)->next = temp;
					n_prev->prev = temp;
					n_prev->next = n_next;

					n_next = n_prev;
					n_prev = temp->prev;
					if ((*list)->prev)
						*list = (*list)->prev;
					print_list(*list);
				}
			}
			temp = n_next;
			if (temp)
			{
				n_next = temp->next;
				n_prev = temp->prev;
			}
		}
	}
}
