#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"
/**
 * add - adds the two top elements,
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
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
void sub(stack_t **stack, unsigned int line_number)
{
	int nofelem = count_stack(*stack), top, rear;

	if (nofelem < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->n;
	rear = (*stack)->prev->n;
	(*stack)->prev->n = top - rear;
	pop(stack, line_number);
}
/**
 * myDiv - divides the second top element of the stack
 * by the second top element of the stack.
 * @stack: the stack
 * @line_number: the line number where the command was found.
 */
void myDiv(stack_t **stack, unsigned int line_number)
{
	int nofelem = count_stack(*stack), top, rear;

	if (nofelem < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->n;
	rear = (*stack)->prev->n;
	if (top == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->prev->n = rear / top;
	pop(stack, line_number);
}
/**
 * mul - multiplies the second element of the stack with the
 * top element and stores the result in the second element
 * @stack: the stack
 * @line_number: the line number where the command was found.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int nofelem = count_stack(*stack), top, rear;

	if (nofelem < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->n;
	rear = (*stack)->prev->n;
	(*stack)->prev->n = top * rear;
	pop(stack, line_number);
}
/**
 * mod - finds the remainder of the division of the second
 * top element of the stack and the top element
 * @stack: the stack
 * @line_number: the line number where the command was found.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int nofelem = count_stack(*stack), top, rear;

	if (nofelem < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = (*stack)->n;
	rear = (*stack)->prev->n;
	if (top == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->prev->n = rear % top;
	pop(stack, line_number);
}
