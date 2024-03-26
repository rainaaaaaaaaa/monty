#include "monty.h"

/**
 * main - Entry point
 * @argc: arguments' count
 * @argv: arguments' vector
 *
 * Description: Monty 0.98 is a scripting language,
 * that is first compiled into Monty byte codes (Just like Python).
 * It relies on a unique stack, with specific instructions to manipulate it.
 * The goal is to create an interpreter for Monty ByteCode files.
 *
 * Return: 0 | EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	int fds;

	struct_state = IN_STACK;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fds = open(argv[1], O_RDONLY);
	if (fds == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	readm(fds);

	close(fds);
	return (0);
}
