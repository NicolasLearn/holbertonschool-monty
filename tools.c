#include "monty.h"

/*---------------------------------------------------------------------------*/
		/*IS_INTEGER*/
/*---------------------------------------------------------------------------*/

/**
 * is_integer - checks if the string is an integer.
 *
 * @str: String to be checked.
 *
 * Return: 1 if an integer. 0 if not.
*/
int is_integer(char *str)
{
	int index = 0, is_int = 1;

	if (str[0] == '-')
		index = 1;
	while (str[index])
	{
		is_int = isdigit(str[index]);
		if (is_int == 0)
			break;
		index++;
	}
	return (is_int);
}

/*---------------------------------------------------------------------------*/
		/*FREE_STACK*/
/*---------------------------------------------------------------------------*/

/**
 * free_stack - free all stack.
 * @head: Pointer to the head of the list.
 */
void free_stack(stack_t *head)
{
	stack_t *nextElement = head;

	while (nextElement != NULL)
	{
		nextElement = head->next;
		free(head);
		head = nextElement;
	}
	head = NULL;
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
