#include "monty.h"


/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @lin: Interger representing the line number of of the opcode.
*/

void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int lin)
{
	stack_t *tmpo;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmpo = head;
	head = *new_node;
	head->next = tmpo;
	tmpo->prev = head;
}


/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_nmber: line number of  the opcode.
*/

void print_stack(stack_t **stack, unsigned int lin_nmber)
{
	stack_t *tmpo;

	(void) lin_nmber;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmpo = *stack;
	while (tmpo != NULL)
	{
		printf("%d\n", tmpo->n);
		tmpo = tmpo->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_nmber: Interger representing the line number of of the opcode.
*/

void pop_top(stack_t **stack, unsigned int lin_nmber)
{
	stack_t *tmpo;

	if (stack == NULL || *stack == NULL)
		more_error(7, lin_nmber);

	tmpo = *stack;
	*stack = tmpo->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmpo);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_nmber: Interger representing the line number of of the opcode.
*/

void print_top(stack_t **stack, unsigned int lin_nmber)
{
	if (stack == NULL || *stack == NULL)
		more_error(6, lin_nmber);
	printf("%d\n", (*stack)->n);
}
