#include "monty.h"

/**
 * atoi_ - change an string into an integer and check error
 * @nptr: the string pointer
 * @endptr: pointer to first, non-nonvalid character
 * @base: the base of conversion
 *
 * Return: read number | 0
 */
int atoi_(char *nptr, char **endptr, int base)
{
	if (nptr && *nptr)
		return (strtol(nptr, endptr, base));
	return (0);
}

/**
 * _reallocate - reallocates a memory block using malloc and free
 * @p: pointer
 * @old_s: old size
 * @new_s: new size
 * Return: pointer | NULL
 */
void *_reallocate(void *p, unsigned int old_s, unsigned int new_s)
{
	void *o;
	char *c, *k;
	unsigned int i;

	if (new_s == old_s && p)
		return (p);
	if (!new_s && p)
	{
		free(p);
		return (0);
	}
	o = malloc(new_s);
	if (!o)
		return (0);
	if (!p)
		return (o);
	i = 0;
	c = o;
	k = p;
	while (i < old_s && i < new_s)
	{
		*c++ = *k++;
		i++;
	}
	free(p);
	return (o);
}

/**
 * free_stk - frees stack memory
 * @stack: stack
 *
 */
void free_stk(stack_t *stack)
{
	stack_t *nxt_e;

	if (!stack)
		return;

	if (struct_state == IN_QUEUE)
	{
		nxt_e = stack->next;
		while (stack)
		{
			free(stack), stack = NULL;
			stack = nxt_e;
			if (nxt_e)
				nxt_e = nxt_e->next;
		}
		return;
	}
	nxt_e = stack->prev;
	while (stack)
	{
		free(stack), stack = NULL;
		stack = nxt_e;
		if (nxt_e)
			nxt_e = nxt_e->prev;
	}
}
