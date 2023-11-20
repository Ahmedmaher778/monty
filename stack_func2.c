#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_nmber: Interger representing the line number of of the opcode.
*/

void nop(stack_t **stack, unsigned int lin_nmber)
{
	(void)stack;
	(void)lin_nmber;
}


/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_nmber: Interger representing the line number of of the opcode.
*/

void swap_nodes(stack_t **stack, unsigned int lin_nmber)
{
	stack_t *tmpo;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, lin_nmber, "swap");
	tmpo = (*stack)->next;
	(*stack)->next = tmpo->next;
	if (tmpo->next != NULL)
		tmpo->next->prev = *stack;
	tmpo->next = *stack;
	(*stack)->prev = tmpo;
	tmpo->prev = NULL;
	*stack = tmpo;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_nmber: Interger representing the line number of of the opcode.
*/

void add_nodes(stack_t **stack, unsigned int lin_nmber)
{
	int sumb;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, lin_nmber, "add");

	(*stack) = (*stack)->next;
	sumb = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sumb;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_nmber: Interger representing the line number of of the opcode.
*/

void sub_nodes(stack_t **stack, unsigned int lin_nmber)
{
	int sumb;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_error(8, lin_nmber, "sub");


	(*stack) = (*stack)->next;
	sumb = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sumb;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_nmber: Interger representing the line number of of the opcode.
*/

void div_nodes(stack_t **stack, unsigned int lin_nmber)
{
	int sumb;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, lin_nmber, "div");

	if ((*stack)->n == 0)
		more_error(9, lin_nmber);
	(*stack) = (*stack)->next;
	sumb = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sumb;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
