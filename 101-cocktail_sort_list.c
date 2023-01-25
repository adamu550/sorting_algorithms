#include "sort.h"
#include <stdio.h>


/**
 * node_swap - swaps a node with the next node in the list
 * @list: double pointer to the beginning of the list
 * @aux: node to swap
 *
 * Return: void
 */
void node_swap(listint_t **list, listint_t *aux)
{
	aux->next->prev = aux->prev;
	if (!aux->prev)
		*list = aux->next;
	else
		aux->prev->next = aux->next;
	aux->prev = aux->next;
	aux->next = aux->next->next;
	aux->prev->next = aux;
	if (aux->next)
		aux->next->prev = aux;
}
/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: double pointer to the beginning of the list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	int mark = 1;
	listint_t *aux1;

	if (list == NULL || *list == NULL)
		return;
	aux1 = *list;
	while (mark != 0)
	{
		mark = 0;
		while (aux1->next)
		{
			if (aux1->next->n < aux1->n)
			{
				node_swap(list, aux1);
				print_list(*list);
				mark = 1;
			}
			else
				aux1 = aux1->next;
		}
		while (aux1->prev)
		{
			if (aux1->prev->n > aux1->n)
			{
				node_swap(list, aux1->prev);
				print_list(*list);
				mark = 1;
			}
			else
				aux1 = aux1->prev;
		}
	}
}
