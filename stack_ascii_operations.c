#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"
/**
 * pchar - prints the char at the top of the stack
 * @stack: the stack
 * @line_number: the line number
 *
 * Description: it gets the integer at the top of the stack,
 * converts it to it's character value the prints it.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int nofelem = count_stack(*stack), a_int;

	if (nofelem == 0)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_mem(stack);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	a_int = (*stack)->n;
	if (a_int < 0 || a_int > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_mem(stack);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)a_int);
}
/**
 * pstr - prints the string starting from the top of the stack,
 * followed by a new line.
 * @stack: the stack
 * @line_number: the line number where the command was found.
 */
void pstr(stack_t **stack, UNUSED unsigned int line_number)
{
	int nofelem = count_stack(*stack), *a_int, i = 0;
	stack_t *tmp = *stack;

	if (nofelem == 0)
	{
		printf("\n");
		return;
	}
	a_int = malloc(nofelem * sizeof(int));
	if (a_int == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (tmp != NULL)
	{
		a_int[i] = tmp->n;
		tmp = tmp->prev;
		i++;
	}
	for (i = 0; i <= nofelem; i++)
	{
		if (a_int[i] < 1 || a_int[i] > 127)
			break;
		printf("%c", a_int[i]);
	}
	printf("\n");
	free(a_int);
}
