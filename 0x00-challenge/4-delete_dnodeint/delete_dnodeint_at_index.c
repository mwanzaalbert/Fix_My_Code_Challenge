#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current_node;
	unsigned int i;

	if (*head == NULL)
	{
		/* List is empty, cannot delete anything */
		return (-1);
	}

	current_node = *head;
	i = 0;

	while (i < index)
	{
		if (current_node == NULL)
		{
			/* Index is out of range */
			return (-1);
		}

		current_node = current_node->next;
		i++;
	}

	if (current_node == NULL)
	{
		/* Index is out of range */
		return (-1);
	}

	if (current_node->prev != NULL)
	{
		/* Not the first node */
		current_node->prev->next = current_node->next;
	}
	else
	{
		/* Deleting the first node, update head */
		*head = current_node->next;
	}

	if (current_node->next != NULL)
	{
		/* Not the last node */
		current_node->next->prev = current_node->prev;
	}

	/* Free the node */
	free(current_node);

	return (1);
}
