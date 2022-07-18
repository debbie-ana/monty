#include "monty.h"

/**
 * free_dlistint - free linked list
 * @h: pointer to first node
 *
 */

void free_dlistint(stack_t *h)
{
	stack_t *tmp;

	while (h != NULL)
	{
		tmp = h->next;
		free(h);
		h = tmp;
	}
}

/**
 * main - main function for the monty interpreter
 * @argc: argument counter
 * @argv: argument vector, monty file
 *
 * Return: integer 0
 */

int main(int argc, char **argv)
{
	stack_t *stack;

	stack = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_file(argv[1], &stack);
	/*to free memory*/
	free_dlistint(stack);
	return (0);
}
