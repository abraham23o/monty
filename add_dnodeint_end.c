#include "monty.h"

/**
 * add_dnodeint_end - adds a new node at the end of a stack
 * @head: double pointer to the head of the stack
 * @n: integer value for the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *temp = *head;

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (!*head)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	while (temp->next)
	{
		temp = temp->next;
	}

	new_node->prev = temp;
	temp->next = new_node;

	return (new_node);
}
