#include "monty.h"

/**
 * _read1 - reads content
 * @b: buffer to be filled
 * @size: buffer size
 * @fds: file descriptor
 *
 * Return: number of characters
 */
int _read1(char *b, unsigned int size, int fds)
{
	unsigned int j;
	int ret;

	for (j = 0; j < size; j++)
		b[j] = '\0';

	ret = read(fds, b, size);
	if (ret == -1)
		fprintf(stderr, "Error: read failed\n"), exit(EXIT_FAILURE);

	return (ret);
}

/**
 * line_s - counts a line's size of characters
 * @b: buffer
 * @i: starting index
 *
 * Return: number of characters in a line
 */
size_t line_s(char *b, int i)
{
	size_t size;

	size = 0;
	while ((i < BUFF_SIZE) && b[i] && b[i] != '\n')
		size++, i++;

	return (size);
}

/**
 * fill_buff - fills buffer
 * @buffer: buffer
 * @i: index
 * @b: pointer
 * @n: pointer
 * @fds: file desciptor
 * @size: size
 *
 * Return: position of i
 */
int fill_buff(char *buffer, int i, char **b, size_t *n,
int fds, size_t size)
{
	size_t new_s;

	new_s = 0;
	for (; buffer[i] != '\n'; i++)
	{
		if (i >= BUFF_SIZE)
		{
			if (_read1(buffer, BUFF_SIZE, fds) == 0)
				break;
			i = 0;
			new_s = size + line_s(buffer, i);
			(*b) = _reallocate(*b, size, new_s);
			i = -1;
		}
		else
			(*b)[(*n)++] = buffer[i];
	}
	(*b)[(*n)] = '\0';

	return (i);
}

/**
 * _getline1 - reads an entire line from file
 * @b: buffer
 * @n: size
 * @fds: file descriptor
 *
 * Return: number of read characters | -1
 */
ssize_t _getline1(char **b, size_t *n, int fds)
{
	static char buffer[BUFF_SIZE];
	static int i;
	size_t size;

	if (i == 0 || i >= BUFF_SIZE || buffer[i] == '\0')
	{
		if (_read1(buffer, BUFF_SIZE, fds) == 0)
			return (-1);
		i = 0;
	}

	if (b && (*b))
		free(*b), *b = NULL;

	size = line_s(buffer, i) + 1;
	*b = malloc(sizeof(char) * size);
	if (!(*b))
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);

	*n = 0;
	i = fill_buff(buffer, i, b, n, fds, size);
	++i;

	return (1);
}
