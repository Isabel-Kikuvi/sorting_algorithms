#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_helper(int *array, int lb, int ub, size_t size);
void swap(int *a, int *b);
int partition(int *array, int upper_bound, int lower_bound, size_t size);
void swap_nodes(listint_t **head, listint_t *n1, listint_t *n2);
void insertion_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
int hoare_partition(int *array, size_t size, int lb, int ub);
void hoare_helper(int *array, size_t size, int lb, int ub);
void quick_sort_hoare(int *array, size_t size);

#endif
