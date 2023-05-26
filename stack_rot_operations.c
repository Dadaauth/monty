#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @stack: the stack
 * @line_number: the line where the command was found
 */
void rotl(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *last = *stack, *prev;

	if (last == NULL)
		return;
	while (last->prev != NULL)
		last = last->prev;

	prev = (*stack)->prev;
	prev->next = NULL;
	(*stack)->next = last;
	last->prev = (*stack);
	(*stack)->prev = NULL;
	(*stack) = prev;
}
