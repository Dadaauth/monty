#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"
/**
 * push - pushes a new element unto the stack
 * @stack: the stack structure
 * @line_number: the line number in the file where the
 * command is coming from.
 */
void push(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *newNode;
	char buffer[BUF_SIZ];
	char *data;
	unsigned int i = 1;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_mem(stack);
		exit(EXIT_FAILURE);
	}
	/* fp (file pointer) is defined globally */
	/**
	 * reset the fgets file position indeicator to point to the
	 * beginning of the file again
	 */
	fseek(fp, 0, SEEK_SET);
	while (i <= line_number)
	{
		fgets(buffer, BUF_SIZ, fp);
		i++;
	}
	strtok(buffer, "	 ");
	data = strtok(NULL, "	 ");
	if (data != NULL)
		clearWhiteSpaceAndTab(data);
	if (data == NULL || strcmp(data, "") == 0 || !isStringInt(data))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	newNode->n = atoi(data);
	newNode->prev = *stack;
	newNode->next = NULL;
	if (*stack != NULL)
		(*stack)->next = newNode;
	*(stack) = newNode;
}
/**
 * pop - removes the top element of the stack
 * @stack: the stack.
 * @line_number: line number of the command in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *prev = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->prev;
	free(prev);
}
