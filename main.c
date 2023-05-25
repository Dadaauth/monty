#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"

/**
 * fp - a global variable for fopen() file
 * pointer to be used across source files
 */
FILE *fp;
/**
 * argCheck - function to check the arguments passed to main
 * @ac: argument count;
 */
void argCheck(int ac)
{
	char *err_str;

	if (ac == 1 || ac > 2)
	{
		err_str = "USAGE: monty file\n";
		fprintf(stderr, "%s", err_str);
		exit(EXIT_FAILURE);
	}
}
/**
 * exec_opcode - executes the opcode into it's various functions
 * @opcode: the opcode
 * @stack: the stack structure
 * @line_number: the line number in the file where the code
 * was encountered.
 * Return: 0 or exit FAILURE.
 */
int exec_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i, size;
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
	};

	size = sizeof(instruction) / sizeof(instruction[0]);
	for (i = 0; i < size; i++)
	{
		if (strcmp(opcode, instruction[i].opcode) == 0)
		{
			instruction[i].f(stack, line_number);
			return (0);
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
/**
 * processByteCode - processes the bytecode passed from
 * the line in the file
 * @buffer: the line gotten from the file
 * @stack: the stack structure
 * Return: 0.
 */
int processByteCode(char *buffer, stack_t **stack)
{
	char *opcode;
	static unsigned int line_number = 1;

	opcode = strtok(buffer, "	 ");
	clearWhiteSpaceAndTab(opcode);

	/* checks if there is a blank line, do nothing */
	if (strcmp(opcode, "") == 0)
	{
		line_number++;
		return (0);
	}

	exec_opcode(opcode, stack, line_number);
	line_number++;
	return (0);
}
/**
 * main - the main function of the program
 * @ac: argument count.
 * @av: argument vector.
 * Return: 0 if everything finished successfully.
 */
int main(int ac, UNUSED char *av[])
{
	char buffer[BUF_SIZ];
	stack_t *stack;
	int i, line;

	argCheck(ac);

	stack = NULL;
	/* note: fp is defined globally */
	fp = openFile(av[1]);
	fgets(buffer, BUF_SIZ, fp);
	for (i = 0; !feof(fp); i++)
	{
		processByteCode(buffer, &stack);
		fseek(fp, 0, SEEK_SET);
		for (line = 0; line <= i; line++)
			fgets(buffer, BUF_SIZ, fp);
		fgets(buffer, BUF_SIZ, fp);
	}
	fclose(fp);
	free_mem(&stack);
	return (0);
}
