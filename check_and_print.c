#include "monty.h"

/*---------------------------------------------------------------------------*/
		/*IS_INSTRUCTION*/
/*---------------------------------------------------------------------------*/

/**
 * is_instruction - check if the input is an instruction.
 *
 * @line: Pointer to the line to be checked.
 * @line_number: Number of the line checked in the file.
 * @stack: Adress to the head of the stack.
 *
 * Return: NULL if success. Pointer to the instruction not found.
*/
char *is_instruction(char *line, unsigned int line_number, stack_t **stack)
{
	int index = 0;
	char *instruction = NULL;
	instruction_t key_word[] = {
		{"pint", print_element}, {"pall", print_stack}, {"add", add_elem},
		{"pop", remove_element}, {"swap", swap_last_elem}, {"nop", nop},
		{NULL, NULL}
	};

	instruction = strtok(line, " \t");
	if (instruction == NULL)
		return (instruction);
	if (is_push_instruction(instruction, line_number, stack))
		instruction = NULL;
	else
	{
		while (key_word[index].opcode)
		{
			if (strcmp(instruction, key_word[index].opcode) == 0)
			{
				key_word[index].f(stack, line_number);
				instruction = NULL;
				break;
			}
			index++;
		}
	}
	return (instruction);
}

/*---------------------------------------------------------------------------*/
		/*IS_PUSH_INSTRUCTION*/
/*---------------------------------------------------------------------------*/

/**
 * is_push_instruction - Check if the instruction is push.
 *
 * @instruc: Pointer to the instruction to be checked.
 * @line_nbr: Number of the line checked in the file.
 * @stack: Adress to the head of the stack.
 *
 * Return: 1 if success. 0 is not.
*/
int is_push_instruction(char *instruc, unsigned int line_nbr, stack_t **stack)
{
	char *str_value = NULL;
	int int_value = 0, ret_val = 0;

	if (strcmp(instruc, "push") == 0)
	{
		str_value = strtok(NULL, " \t");
		int_value = atoi(str_value);
		if ((int_value == 0) && (strcmp(str_value, "0") != 0))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_nbr);
			exit(EXIT_FAILURE);
		}
		push_element(int_value, stack);
		ret_val = 1;
	}
	return (ret_val);
}

/*---------------------------------------------------------------------------*/
		/*PRINT_ELEMENT*/
/*---------------------------------------------------------------------------*/

/**
 * print_element - Print the value of the last element added on the stack.
 *
 * @stack: Adress to the head of the stack.
 * @line_number: Number of the line checked in the file.
*/

void print_element(stack_t **stack, unsigned int line_number)
{
	stack_t *buf_stack = *stack;

	if (buf_stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", buf_stack->n);
}

/*---------------------------------------------------------------------------*/
		/*PRINT_STACK*/
/*---------------------------------------------------------------------------*/

/**
 * print_stack - Print all value of the stack.
 *
 * @stack: Adress to the head of the stack.
 * @line_number: Unused.
*/

void print_stack(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *buf_stack = *stack;

	while (buf_stack)
	{
		printf("%d\n", buf_stack->n);
		buf_stack = buf_stack->next;
	}
}

/*---------------------------------------------------------------------------*/
		/*NOP*/
/*---------------------------------------------------------------------------*/

/**
 * nop - Doesn’t do anything.
 *
 * @stack: Unused.
 * @line_number: Unused.
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void) *stack;
	(void) line_number;
}
