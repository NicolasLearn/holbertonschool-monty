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
