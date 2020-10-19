#ifndef _SORT_H_
#define _SORT_H_
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
listint_t *create_listint(const int *array, size_t size);
void selection_sort(int *array, size_t size);
void swap(int *num1, int *num2);
void quick_sort(int *array, size_t size);
void quicksort(int *array, ssize_t pos_init, ssize_t right_pos, size_t size);
int partition(int *array, ssize_t pos_init, ssize_t right_pos, size_t size);
void shell_sort(int *array, size_t size);
void swap_s(int check, int prev, int gap, int *i_arr);
void shell_sort(int *array, size_t size);


#endif
