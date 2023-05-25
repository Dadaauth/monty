#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"
/**
 * pall - prints or displays all elements in the stack
 * @stack: the stack
 * @line_number: the line number where the command was found
 */
void pall(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
}
/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: the stack
 * @line_number: the line number where the command was found.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
