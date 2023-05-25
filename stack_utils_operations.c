#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @stack: the stack
 * @line_number: the line number on the file that the command came from
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int top, rear, nofelem = 0;
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		tmp = tmp->prev;
		nofelem++;
	}
	if (nofelem < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->n;
	rear = (*stack)->prev->n;
	(*stack)->n = rear;
	(*stack)->prev->n = top;
}
