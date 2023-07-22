#include "sort.h"

void swap_before(listint_t **list, listint_t **tail, listint_t **current);
void swap_after(listint_t **list, listint_t **tail, listint_t **current);
void cocktail_sort_list(listint_t **list);

/**
 * cocktail_sort_list - Sort a listint_t using the cocktail shaker algorithm.
 * @list: A pointer to the head.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *current;
	bool not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (not_stirred == false)
	{
		not_stirred = true;
		for (current = *list; current != tail; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_before(list, &tail, &current);
				print_list((const listint_t *)*list);
				not_stirred = false;
			}
		}
		for (current = current->prev; current != *list;
				current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_after(list, &tail, &current);
				print_list((const listint_t *)*list);
				not_stirred = false;
			}
		}
	}
}
/**
 * swap_before - Swap a node with the node ahead of it
 * @list: A pointer to the head of list
 * @tail: A pointer to the tail of list
 * @current: A pointer to the current node
 */
void swap_before(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*current)->prev;
	(*current)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *current;
	else
		*tail = *current;
	(*current)->prev = temp;
	temp->next = *current;
	*current = temp;
}
/**
 * swap_after - Swap a node with the node after it.
 * @list: A pointer to the head
 * @tail: A pointer to the tail]
 * @current: A pointer to the current node
 */
void swap_after(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*current)->next;
	(*current)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *current;
	else
		*list = *current;
	(*current)->next = temp;
	temp->prev = *current;
	*current = temp;
}
