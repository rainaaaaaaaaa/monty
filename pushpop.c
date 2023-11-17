#include "monty.h"

/**
 * push_ - pushes data
 * @stack: pointer
 * @line_order: line number
 *
 */
void push_(stack_t **stack, unsigned int line_order)
{
	int n;
	char *s, *nonvalid;

	nonvalid = "";
	s = strtok(NULL, "\t\n ");
	if (s && nonvalid)
		n = atoi_(s, &nonvalid, 10);
	if (!s || *nonvalid != '\0')
	{
		fprintf(stderr, "L%u: usage: push_ integer\n", line_order);
		exit(EXIT_FAILURE);
	}
	if (struct_state == IN_STACK)
		addto_tos(stack, n);
	else
		addto_q(stack, n);
}

/**
 * pall_ - prints elements of a stack
 * @stack: pointer
 * @line_order: line number
 *
 */
void pall_(stack_t **stack, __attribute__((unused))unsigned int line_order)
{
	stack_t *tm;

	if (!stack)
		return;
	tm = *stack;
	while (tm)
	{
		printf("%d\n", tm->n);
		if (struct_state == IN_STACK)
			tm = tm->prev;
		else
			tm = tm->next;
	}
}

/**
 * pint_2 - print an item at top of stack
 * @stack: pointer
 * @line_order: line order
 */
void pint_2(stack_t **stack, __attribute__((unused))unsigned int line_order)
{
	if (stack && *stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint_2, stack vide\n", line_order);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop_ - removes elements of stack
 * @stack: pointer
 * @line_order: line number
 *
 */
void pop_(stack_t **stack, unsigned int line_order)
{
	stack_t *poppe = pop_2(stack, line_order);

	free(poppe);
}

/**
 * pop_2 - pop_ an element from the stack and return it
 * @stack: pointer
 * @line_order: line number
 *
 * Return: the removed item
 */
stack_t *pop_2(stack_t **stack, unsigned int line_order)
{
	stack_t *poppe, *new_t;

	if (stack && !(*stack))
	{
		fprintf(stderr, "L%u: can't pop_ an vide stack\n", line_order);
		exit(EXIT_FAILURE);
	}

	if (struct_state == IN_STACK)
	{
		new_t = (*stack)->prev;
		if (new_t)
			new_t->next = NULL;
	}
	else
	{
		new_t = (*stack)->next;
		if (new_t)
			new_t->prev = NULL;
	}
	poppe = *stack;
	*stack = new_t;
	return (poppe);
}
