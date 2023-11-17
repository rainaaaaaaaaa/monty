#include "monty.h"

/**
 * execm - executes an instruction of Monty bytecode
 * @instruction: bytecode instruction
 * @ln: line number
 * @top: pointer to top of the stack
 *
 */
void execm(char *instruction, unsigned int ln, stack_t **top)
{
	char *opcode;
	void (*f)(stack_t **, unsigned int);

	opcode = _opcode(instruction);
	if (opcode && opcode[0] != '#')
	{
		f = _instruction(opcode);
		if (!f)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", ln, opcode);
			exit(EXIT_FAILURE);
		}
		f(top, ln);
	}
}
