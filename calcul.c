#include "monty.h"

/**
 * added - adds top two elements of stack
 * @stack: pointer to top of the stack
 * @line_order: opcode' line number
 *
 */
void added(stack_t **stack, unsigned int line_order)
{
	if (stack && (!(*stack) || !(*stack)->prev))
	{
		fprintf(stderr, "L%u: can't added, stack too short\n", line_order);
		free_stk(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->prev->n += (*stack)->n;
	pop_(stack, line_order);
}

/**
 * subtract - subtracts top two elements of stack (2TOS - TOS)
 * @stack: pointer to top of the stack
 * @line_order: opcode' line number
 *
 */
void subtract(stack_t **stack, unsigned int line_order)
{
	if (stack && (!(*stack) || !(*stack)->prev))
	{
		fprintf(stderr, "L%u: can't subtract, stack too short\n", line_order);
		free_stk(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->prev->n -= (*stack)->n;
	pop_(stack, line_order);
}

/**
 * multiply - multiplies elements
 * @stack: pointer
 * @line_order: line number
 *
 */
void multiply(stack_t **stack, unsigned int line_order)
{
	if (stack && (!(*stack) || !(*stack)->prev))
	{
		fprintf(stderr, "L%u: can't multiply, stack too short\n", line_order);
		free_stk(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->prev->n *= (*stack)->n;
	pop_(stack, line_order);
}

/**
 * divise - perform a division
 * @stack: pointer
 * @line_order: line number
 *
 */
void divise(stack_t **stack, unsigned int line_order)
{
	stack_t *top;

	if (stack && *stack && (*stack)->prev)
	{
		top = pop_2(stack, line_order);
		if (top->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_order);
			exit(EXIT_FAILURE);
		}
		(*stack)->n = (*stack)->n / top->n;
		free(top);
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_order);
		exit(EXIT_FAILURE);
	}
}

/**
 * modulo - return modulo of division
 * @stack: pointer
 * @line_order: line number
 *
 */
void modulo(stack_t **stack, unsigned int line_order)
{
	stack_t *top;

	if (stack && *stack && (*stack)->prev)
	{
		top = pop_2(stack, line_order);
		if (top->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_order);
			exit(EXIT_FAILURE);
		}
		(*stack)->n = (*stack)->n % top->n;
		free(top);
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_order);
		exit(EXIT_FAILURE);
	}
}
