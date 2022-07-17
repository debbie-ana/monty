#include "monty.h"

/**
 * _push - push number to a stack
 * @stack: linked lists for monty stack
 * @line_number: line number of opcode
 */

void _push(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *top;
	(void)line_number;

	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	top->n = var_g.arg;
	top->next = *stack;
	top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = top;
	*stack = top;
}

void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *r;

	r = *stack;
	while (r != NULL)
	{
		printf("%d\n", r->n);
		r = r->next;
	}
}
