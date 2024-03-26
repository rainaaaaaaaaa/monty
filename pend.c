#include "monty.h"

/**
 * p_char - print a char
 * @stack: stack
 * @line_order: line order
 */
void p_char(stack_t **stack, unsigned int line_order)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't p_char, stack vide\n", line_order);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%u: can't p_char, value out of range\n", line_order);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * vide - writes buffer to stdout and frees it
 * @buffer: buffer
 *
 * Return: 0
 */
unsigned int vide(char *buffer)
{
	int i;

	write(STDOUT_FILENO, buffer, 100);
	for (i = 0; i < 100; i++)
		buffer[i] = '\0';
	return (0);
}

/**
 * p_str - prints string
 * @stack: pointer
 * @line_order: line number
 *
 */
void p_str(stack_t **stack, __attribute__((unused))unsigned int line_order)
{
	unsigned int i;
	char buffer[100];
	stack_t *tm;

	i = 0;
	if (stack)
		tm = *stack;
	else
		tm = NULL;
	while (tm)
	{
		if (i >= 100)
			i = vide(buffer);

		if (tm->n < 1 || tm->n > 127)
			break;
		buffer[i++] = tm->n;

		tm = tm->prev;
	}

	buffer[i++] = '\n';
	write(STDOUT_FILENO, buffer, i);
}
