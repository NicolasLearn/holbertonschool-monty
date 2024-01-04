#include "monty.h"

/*---------------------------------------------------------------------------*/
		/*PUSH_ELEMENT*/
/*---------------------------------------------------------------------------*/

/**
 * push_element - Create a stack element and add it to the top of the stack.
 *
 * @value: Is the value of the new stack element.
*/
void push_element(int value)
{
	stack_t *new_element;

	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
	{
		free(new_element);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (head_stack == NULL)
		new_element->next = NULL;
	else
	{
		head_stack->prev = new_element;
		new_element->next = head_stack;
	}
	new_element->n = value;
	new_element->prev = NULL;
	head_stack = new_element;
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
		/*SWAP_LAST_ELEM*/
/*---------------------------------------------------------------------------*/

/**
 * swap_last_elem - Swaps the top two elements of the stack.
 *
 * @stack: Adress to the head of the stack.
 * @line_number: Number of the line checked in the file.
*/
void swap_last_elem(stack_t **stack, unsigned int line_number)
{
	stack_t *buff_stak = *stack;
	int buf_value;

	if ((buff_stak == NULL) || (buff_stak->next == NULL))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	buf_value = buff_stak->n;
	buff_stak->n = buff_stak->next->n;
	buff_stak->next->n = buf_value;
}

/*---------------------------------------------------------------------------*/
		/*REMOVE_ELEMENT*/
/*---------------------------------------------------------------------------*/

/**
 * remove_element - Removes the top element of the stack.
 * @stack: Adress to the head of the stack.
 * @line_number: Number of the line checked in the file.
 *
 * If the stack is empty, the function prints an error message and exits.
 */

void remove_element(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	if (temp->next != NULL)
		temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
