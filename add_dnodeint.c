#include "monty.h"
/**
 * add_dnodeint - adds a new node at the beginning of a stack
 * @head: double pointer to the head of the stack
 * @n: integer value for the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head)
	{
		(*head)->prev = new_node;
	}

	*head = new_node;
	return (new_node);
}
