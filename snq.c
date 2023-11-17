#include "monty.h"

/**
 * stack - from queue mode to stack mode
 * @stack: pointer
 * @line_order: line order
 */
void stack(stack_t **stack, __attribute__((unused))unsigned int line_order)
{
	stack_t *nod1, *nod2, *lag;

	if (struct_state == IN_QUEUE)
	{
		if (*stack && (*stack)->next)
		{
			lag = *stack;
			nod1 = (*stack)->next;
			while (nod1)
			{
				nod2 = nod1->next;

				lag->prev = nod1;
				nod1->next = lag;

				lag = nod1;
				nod1 = nod2;
			}
			lag->prev = NULL;
		}
		struct_state = IN_STACK;
	}
}

/**
 * queue_ - from queue mode to stack mode
 * @stack: pointer
 * @line_order: line order
 */
void queue_(stack_t **stack, __attribute__((unused))unsigned int line_order)
{
	stack_t *nod1, *nod2, *lag;

	if (struct_state == IN_STACK)
	{
		if (*stack && (*stack)->prev)
		{
			lag = *stack;
			nod1 = (*stack)->prev;
			while (nod1)
			{
				nod2 = nod1->prev;

				lag->next = nod1;
				nod1->prev = lag;

				lag = nod1;
				nod1 = nod2;
			}
			lag->next = NULL;
		}
		struct_state = IN_QUEUE;
	}
}
