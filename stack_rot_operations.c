#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "monty.h"
/**
 * rotl - rotates the stack to the top,
 * the top elements becomes the last
 * @stack: the stack
 * @line_number: the line where the command was found
 */
void rotl(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *last = *stack, *prev;

	if (*stack == NULL)
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
/**
 * rotr - rotates the stack to the bottom,
 * the last element becomes the top.
 * @stack: the stack
 * @line_number: the line number where the program was found.
 */
void rotr(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *last = *stack, *prev;

	if (*stack == NULL)
		return;
	while (last->prev != NULL)
		last = last->prev;

	prev = last->next;
	(*stack)->next = last;
	last->next = NULL;
	prev->next = NULL;
}
