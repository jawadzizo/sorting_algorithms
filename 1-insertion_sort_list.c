#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list's nodes using
 *				insertion algorithm
 * @list: a pointer to the pointer of the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr = *list;
	listint_t *temp;

	if ((ptr == NULL) || (ptr->next == NULL))
		return;

	while (ptr->next != NULL)
	{
		if (ptr->n > ptr->next->n)
		{
			swap_nodes(ptr, ptr->next, list);
			print_list(*list);

			for (temp = ptr->prev; temp->prev != NULL; temp = temp->prev)
			{
				if (temp->n < temp->prev->n)
				{
					swap_nodes(temp, temp->prev, list);
					print_list(*list);
				}
			}
		}

		ptr = ptr->next;
	}
}


/**
 * swap_nodes - swaps 2 doubly linked list's nodes
 * @p1: the first node
 * @p2: the second node
 * @head: a pointer to ointer of the doubly linked list's head
 */
void swap_nodes(listint_t *p1, listint_t *p2, listint_t **head)
{
	listint_t *temp;

	if (p2->next != NULL)
		p2->next->prev = p1;

	if (p1->prev != NULL)
		p1->prev->next = p2;

	p1->next = p2->next;
	temp = p1->prev;
	p1->prev = p2;
	p2->next = p1;
	p2->prev = temp;

	if (*head == p1)
		*head = p2;
}
