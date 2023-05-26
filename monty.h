#ifndef MONTY_H
#define MONTY_H

#define BUF_SIZ 200
#define UNUSED __attribute__ ((unused))
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode.
 *
 * Description: opcode and it's function
 * for stack, queues, LIFO, FIFO .
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* function declarations */
#define div myDiv
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void myDiv(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

int count_stack(stack_t *stack);
FILE *openFile(char *filepath);
void clearWhiteSpaceAndTab(char *str);
int processByteCode(char *buffer, stack_t **stack);
bool isStringInt(const char *str);
void free_mem(stack_t **stack);


/* variable declarations */
extern FILE *fp;

#endif
