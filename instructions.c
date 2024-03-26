#include "monty.h"

/**
 * _opcode - get opcode from line
 * @line: line
 *
 * Return: opcode | NULL
 */
char *_opcode(char *line)
{
	const char *del;
	char *opcode;

	if (!line)
		return (NULL);

	del = "\n\t ";
	opcode = strtok(line, del);
	return (opcode);
}

/**
 * _instruction - get opcode's matching function
 * @opcode: opcode
 *
 * Return: pointer | NULL
 */
void (*_instruction(char *opcode))(stack_t **, unsigned int)
{
	instruction_t list[] = {
		{"swap", swap_}, {"push", push_},
		{"pall", pall_}, {"pop", pop_},
		{"add", added}, {"sub", subtract},
		{"mul", multiply}, {"pint", pint_2},
		{"pstr", p_str},	{"rotr", rotate},
		{"nop", nop_}, {"div", divise},
		{"mod", modulo}, {"pchar", p_char},
		{"rotl", rotate_l}, {"queue", queue_},
		{"stack", stack},
		{NULL, NULL}
	};
	unsigned int i;

	for (i = 0; list[i].opcode; i++)
	{
		if (strcmp(opcode, list[i].opcode) == 0)
			return (list[i].f);
	}
	return (NULL);
}
