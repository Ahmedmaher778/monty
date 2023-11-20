#include "monty.h"

/**
 * mul_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_nmber: Interger representing the line number of of the opcode.
*/

void mul_nodes(stack_t **stack, unsigned int lin_nmber)
{
	int sumb;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_error(8, lin_nmber, "mul");

	(*stack) = (*stack)->next;
	sumb = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sumb;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_nmber: Interger representing the line number of of the opcode.
*/

void mod_nodes(stack_t **stack, unsigned int lin_nmber)
{
	int sumb;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_error(8, lin_nmber, "mod");


	if ((*stack)->n == 0)
		more_error(9, lin_nmber);
	(*stack) = (*stack)->next;
	sumb = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sumb;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
