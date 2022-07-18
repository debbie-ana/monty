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

/**
 * _pall - prints all elements in stack
 * @stack: pointer to linked list stack
 * @line_number: line number of opcode
 *
 */

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

/**
 * _pint - prints the topmost element of stack
 * @stack: pointer to linked list stack
 * @line_number: line number of opcode
 *
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *r;

	r = *stack;
	if (r == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", r->n);
}

/**
 * _pop - removes the top element of the stack
 * @stack: pointer to linked list stack
 * @line_number: line number of opcode
 *
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *r = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = r->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(r);
}

/**
 * _swap - swaps the top two elements of the stack
 * @stack: pointer to linked list stack
 * @line_number: line number of opcode
 *
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *r;
	int a;

	r = *stack;
	if (r == NULL || r->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	a = r->n;
	r->n = r->next->n;
	r->next->n = a;
}
