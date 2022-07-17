#include "monty.h"

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
