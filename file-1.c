#include "monty.h"

/*---------------------------------------------------------------------------*/
		/*IS_INSTRUCTION*/
/*---------------------------------------------------------------------------*/

/**
 * is_instruction -
 *
 * @line:
 * @line_number:
*/
void is_instruction(char *line, unsigned int line_number)
{
	int index = 0;
	char *instruction = NULL;
	instruction_t key_word[] = {
		{"pall", NULL},
		{NULL, NULL}
	};

	instruction = strtok(line, " ");
	if (instruction == NULL)
		return;
	if (is_push_instruction(instruction, line_number))
		return;
	else
	{
		while (key_word[index].opcode)
		{
			if (strcmp(instruction, key_word[index].opcode) == 0)
			{
				printf("L%d : instruction = <%s>\n", line_number, instruction);
				/*key_word[index].f(head_stack, line_number);*/
				break;
			}
			index++;
		}

	}
}

/*---------------------------------------------------------------------------*/
		/*IS_DIGIT*/
/*---------------------------------------------------------------------------*/

/**
 * is_push_instruction -
 *
 * @instruction:
 * @line_number:
 *
 * Return:
*/
int is_push_instruction(char *instruction, unsigned int line_number)
{
	char * str_value = NULL;
	int int_value = 0, ret_val = 0;

	if (strcmp(instruction, "push") == 0)
	{
		str_value = strtok(NULL, " ");
		int_value = atoi(str_value);
		if (int_value == 0)
			fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		/*push_element(head_stack, int_value);*/
		printf("L%d : instruction = <%s>. Value = <%d>\n", line_number, instruction, int_value);
		ret_val = 1;
	}

	return (ret_val);
}
