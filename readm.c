#include "monty.h"

/**
 * readm - reads the monty bytescode
 * @fds: file desciptor
 *
 */
void readm(int fds)
{
	char *buffer;
	size_t i;
	unsigned int line_order;
	stack_t *top;

	top = NULL;
	buffer = NULL, i = 0;

	/* execute one line\instruction at a time */
	line_order = 1;
	while (_getline1(&buffer, &i, fds) != -1)
	{
		execm(buffer, line_order, &top);
		line_order++;
	}

	free(buffer);
	free_stk(top);
}
