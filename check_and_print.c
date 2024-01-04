#include "monty.h"

/*---------------------------------------------------------------------------*/
		/*IS_INSTRUCTION*/
/*---------------------------------------------------------------------------*/

/**
 * is_instruction - check if the input is an instruction.
 *
 * @line: Pointer to the line to be checked.
 * @line_number: Number of the line checked in the file.
 *
 * Return: NULL if success. Pointer to the instruction not found.
*/
char *is_instruction(char *line, unsigned int line_number)
{
	int index = 0;
	char *instruction = NULL;
	instruction_t key_word[] = {
		{"pint", print_element}, {"pall", print_stack}, {"add", NULL},
		{"pop", NULL}, {"swap", NULL}, {"nop", NULL},
		{NULL, NULL}
	};

	instruction = strtok(line, " ");
	if (instruction == NULL)
		return (instruction);
	if (is_push_instruction(instruction, line_number))
		instruction = NULL;
	else
	{
		while (key_word[index].opcode)
		{
			if (strcmp(instruction, key_word[index].opcode) == 0)
			{
				key_word[index].f(&head_stack, line_number);
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
 * @instruction: Pointer to the instruction to be checked.
 * @line_number: Number of the line checked in the file.
 *
 * Return: 1 if success. 0 is not.
*/
int is_push_instruction(char *instruction, unsigned int line_number)
{
	char *str_value = NULL;
	int int_value = 0, ret_val = 0;

	if (strcmp(instruction, "push") == 0)
	{
		str_value = strtok(NULL, " ");
		int_value = atoi(str_value);
		if ((int_value == 0) && (strcmp(str_value, "0") != 0))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		push_element(int_value);
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
 * @stack: Unused.
 * @line_number: Unused.
*/

void print_element(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	if (head_stack != NULL)
		printf("%d\n", head_stack->n);
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
