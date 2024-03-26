#include "monty.h"

/**
 * swap_ - swap_ TOS item
 * @stack: pointer
 * @line_order: line order
 *
 */
void swap_(stack_t **stack, unsigned int line_order)
{
	stack_t *tos_node, *next_tos;

	if (*stack && (*stack)->prev)
	{
		tos_node = pop_2(stack, line_order);
		next_tos = *stack;
		if (struct_state == IN_STACK)
		{
			tos_node->prev = next_tos->prev;
			if (next_tos->prev)
				next_tos->prev->next = tos_node;
			tos_node->next = next_tos;
			next_tos->prev = tos_node;
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't swap_, stack too short\n", line_order);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop_ - do nothing at all
 * @stack: pointer
 * @line_order: line number
 *
 */
void nop_(stack_t **stack, unsigned int line_order)
{
	(void)stack, (void)line_order;
}
