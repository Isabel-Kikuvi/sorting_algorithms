#include "sort.h"

/**
 * swap_nodes - swaps two nodes
 * @head: double pointer to the head of list
 * @n1: the first node to swap
 * @n2: second node to swap
 */

void swap_nodes(listint_t **head, listint_t *n1, listint_t *n2)
{
	listint_t *prev, *next;

	prev = n1->prev;
	next = n2->next;

	if (prev != NULL)
		prev->next = n2;
	else
		*head = n2;

	n1->prev = n2;
	n1->next = next;
	n2->prev = prev;
	n2->next = n1;
	if (next)
		next->prev = n1;
}

/**
 * insertion_sort_list - sorts  list using insertion
 * @list: the list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *nxt, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (nxt = (*list)->next; nxt && nxt->prev; nxt = nxt->next)
	{
		for (; nxt && nxt->prev && nxt->n < nxt->prev->n;
		     nxt = nxt->prev)
		{
			tmp = nxt->prev;
			swap_nodes(list, tmp, nxt);
			print_list(*list);
			nxt = nxt->next;
		}
	}
}

