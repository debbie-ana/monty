#define _GNU_SOURCE
#include "monty.h"

/**
 * read_file - reads the monty file and runs commands
 * @fname: name of the file
 * @stack: pointer to top of the stack
 *
 * Return: void
 */

void read_file(char *fname, stack_t **stack)
{
	char *line;
	size_t a = 0;
	int line_cnt = 1;
	instruct_func fnc;
	int check;
	ssize_t read;

	var_g.file = fopen(fname, "r");

	if (var_g.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fname);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&(var_g.buffer), &a, var_g.file)) != -1)
	{
		line = parse_line(var_g.buffer, stack, line_cnt);
		if (line == NULL || line[0] == '#')
		{
			line_cnt++;
			continue;
		}
		fnc = get_opfunc(line);
		if (fnc == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_cnt, line);
			exit(EXIT_FAILURE);
		}
		fnc(stack, line_cnt);
		line_cnt++;
	}
	free(var_g.buffer);
	check = fclose(var_g.file);
	if (check == -1)
		exit(-1);
}

/**
 * get_opfunc - checks opcode and returns function relating to it
 * @op: the opcode
 * Return: function for opcode, or NULL if failed
 */
instruct_func get_opfunc(char *op)
{
	int i;

	instruction_t ins[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL},
	};

	i = 0;
	while (ins[i].f != NULL && strcmp(ins[i].opcode, op) != 0)
		i++;
	return (ins[i].f);
}
/**
 * isnumber - checks if str is a number
 * @str: string
 *
 * Return: 1 if string is a number, 0 otherwise
 */

int isnumber(char *str)
{
	unsigned int i = 0;

	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[0] == '-')
		{
			i++;
			continue;
		}
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * parse_line - parses a line for opcode and arguments
 * @line: line to be parsed
 * @stack: pointer to top of the stack
 * @line_number: current line number
 *
 * Return: opcode or NULL if failed
 */

char *parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *op_code, *push, *arg;
	(void)stack;

	push = "push";
	op_code = strtok(line, "\n ");
	if (op_code == NULL)
		return (NULL);

	if (strcmp(op_code, push) == 0)
	{
		arg = strtok(NULL, "\n ");
		if (isnumber(arg) == 1 && arg != NULL)
		{
			var_g.arg = atoi(arg);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n",
					line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (op_code);
}
