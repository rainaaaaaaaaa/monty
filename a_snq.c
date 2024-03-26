#include "monty.h"

/**
 * addto_tos - adds elements to top of the stack
 * @stack: pointer
 * @n: element
 *
 * Return: pointer
 */
stack_t *addto_tos(stack_t **stack, int n)
{
	stack_t *new_e;

	new_e = malloc(sizeof(*new_e));
	if (!new_e)
		fprintf(stderr, "Error: malloc failed"), exit(EXIT_FAILURE);
	new_e->n = n, new_e->prev = NULL, new_e->next = NULL;

	if (!stack || !(*stack))
		*stack = new_e;
	else
	{
		(*stack)->next = new_e;
		new_e->prev = (*stack);
		*stack = new_e;
	}

	return (new_e);
}

/**
 * addto_q - adds elements to head of the queue
 * @stack: pointer
 * @n: element
 *
 * Return: pointer
 */
stack_t *addto_q(stack_t **stack, int n)
{
	stack_t *new_e, *node;

	new_e = malloc(sizeof(*new_e));
	if (!new_e)
		fprintf(stderr, "Error: malloc failed"), exit(EXIT_FAILURE);
	new_e->n = n, new_e->prev = NULL, new_e->next = NULL;

	if (!stack || !(*stack))
		*stack = new_e;
	else
	{
		node = *stack;
		while (node->next)
			node = node->next;
		node->next = new_e;
		new_e->prev = node;
	}

	return (new_e);
}
