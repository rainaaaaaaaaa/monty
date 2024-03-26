#include "monty.h"

/**
 * rotate_l - rotate the linkedlist items
 * @stack: pointer
 * @line_order: line order
 *
 */
void rotate_l(stack_t **stack, unsigned int line_order)
{
	stack_t *node, *poppe;

	if (stack && *stack && (*stack)->prev)
	{
		poppe = pop_2(stack, line_order);
		node = *stack;
		while (node->prev)
			node = node->prev;
		node->prev = poppe;
		poppe->next = node;
		poppe->prev = NULL;
	}
}

/**
 * rotate - rotates stack
 * @stack: pointer
 * @line_order: line number
 *
 */
void rotate(stack_t **stack, __attribute__((unused))unsigned int line_order)
{
	stack_t *last;

	if (!stack || !(*stack) || !(*stack)->prev)
		return;

	last = *stack;
	while (last && last->prev)
		last = last->prev;

	last->next->prev = NULL;
	last->prev = *stack;
	last->next = NULL;
	(*stack)->next = last;

	*stack = last;
}
