#include "sort.h"

/**
 * swap - Swap nodes
 * @head: A pointer to the head
 * @node1: A pointer to the first node
 * @node2: The second node to swap.
 */
void swap(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - using the insertion sort algorithm to sort
 * a doubly linkedlist
 * @list: A pointer to the head of the kist
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *loop, *insert, *tempnode;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (loop = (*list)->next; loop != NULL; loop = tempnode)
	{
		tempnode = loop->next;
		insert = loop->prev;
		while (insert != NULL && loop->n < insert->n)
		{
			swap(list, &insert, loop);
			print_list((const listint_t *)*list);
		}
	}
}
