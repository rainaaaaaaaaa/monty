#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#define BUFF_SIZE 1024
#define IN_QUEUE 1
#define IN_STACK 0

int struct_state;

void readm(int);
void execm(char *, unsigned int, stack_t **);
char *_opcode(char *line);
void (*_instruction(char *opcode))(stack_t **, unsigned int);
void push_(stack_t **stack, unsigned int line_order);
stack_t *addto_tos(stack_t **stack, int n);
void pall_(stack_t **stack, __attribute__((unused))unsigned int line_order);
ssize_t _getline1(char **, size_t *, int);
void free_stk(stack_t *stack);
int atoi_(char *nptr, char **endptr, int base);
void pop_(stack_t **, unsigned int);
void added(stack_t **stack, unsigned int line_order);
void pint_2(stack_t **stack, __attribute__((unused))unsigned int line_order);
stack_t *pop_2(stack_t **stack, unsigned int line_order);
void swap_(stack_t **stack, unsigned int line_order);
void nop_(stack_t **stack, unsigned int line_order);
void subtract(stack_t **stack, unsigned int line_order);
void multiply(stack_t **stack, unsigned int line_order);
int _read1(char *b, unsigned int size, int fds);
size_t line_s(char *b, int i);
int fill_buff(char *buffer, int i, char **b, size_t *n, int fds, size_t size);
unsigned int vide(char *buffer);
void p_str(stack_t **stack, unsigned int line_order);
void rotate(stack_t **stack, unsigned int line_order);
void divise(stack_t **stack, unsigned int line_order);
void modulo(stack_t **stack, unsigned int line_order);
void p_char(stack_t **stack, unsigned int line_order);
void rotate_l(stack_t **stack, unsigned int line_order);
void stack(stack_t **stack, __attribute__((unused))unsigned int line_order);
void queue_(stack_t **stack, __attribute__((unused))unsigned int line_order);
stack_t *addto_q(stack_t **stack, int n);
void *_reallocate(void *p, unsigned int old_s, unsigned int new_s);

#endif
