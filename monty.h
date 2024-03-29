#ifndef __MONTY_H__
#define __MONTY_H__

/*---------------------------------------------------------------------------*/
		/*LIBRAIRY*/
/*---------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*---------------------------------------------------------------------------*/
		/*STRUCT*/
/*---------------------------------------------------------------------------*/

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
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*---------------------------------------------------------------------------*/
		/*PROTOTYPE file : CHECK_AND_PRINT*/
/*---------------------------------------------------------------------------*/

char *is_instruction(char *line, unsigned int line_number, stack_t **stack);
int is_push_instruction(char *instruction, unsigned int, stack_t **stack);
void print_element(stack_t **stack, unsigned int line_number);
void print_stack(stack_t **stack, unsigned int line_number);

/*---------------------------------------------------------------------------*/
		/*PROTOTYPE file : MANIP_STACK*/
/*---------------------------------------------------------------------------*/

void push_element(int value, stack_t **stack);
void swap_last_elem(stack_t **stack, unsigned int line_number);
void remove_element(stack_t **stack, unsigned int line_number);
void add_elem(stack_t **stack, unsigned int line_number);

/*---------------------------------------------------------------------------*/
		/*PROTOTYPE file : TOOLS*/
/*---------------------------------------------------------------------------*/

int is_integer(char *str);
void free_stack(stack_t *head);
void nop(stack_t **stack, unsigned int line_number);

#endif
