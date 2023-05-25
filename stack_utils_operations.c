#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"
/**
 * count_stack - returns the amount of elements in the stack
 * @stack: the stack
 * Return: the number of elements
 */
int count_stack(stack_t *stack)
{
	int nofelem = 0;

	while (stack != NULL)
	{
		stack = stack->next;
		nofelem++;
	}
	return (nofelem);
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: the stack
 * @line_number: the line number on the file that the command came from
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int top, rear, nofelem = 0;

	nofelem = count_stack(*stack);
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
/**
 * add - addds the two top elements,
 * saves the result in the second top
 * element and removes the topmost element
 * @stack: the stack
 * @line_number: the line_number
 */
void add(stack_t **stack, unsigned int line_number)
{
	int nofelem = count_stack(*stack), top, rear;

	if (nofelem < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->n;
	rear = (*stack)->prev->n;
	(*stack)->prev->n = top + rear;
	pop(stack, line_number);
}
/**
 * sub - subtracts the first top element from the second top element
 * result is stored in the second element,
 * then the topmost element is removed.
 * @stack: the stack
 * @line_number: the line number in the file where the command is found
 */
/**
 * nop - does nothing
 * @stack: the stack
 * @line_number: the line number
 */
void nop(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{

}
