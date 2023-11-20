#include "monty.h"

/**
 * print_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin_nmber: Interger representing the line number of of the opcode.
*/

void print_char(stack_t **stack, unsigned int lin_nmber)
{
	int asci;

	if (stack == NULL || *stack == NULL)
		string_error(11, lin_nmber);

	asci = (*stack)->n;
	if (asci < 0 || asci > 127)
		string_error(10, lin_nmber);
	printf("%c\n", asci);
}

/**
 * print_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin: Interger representing the line number of of the opcode.
*/

void print_str(stack_t **stack, __attribute__((unused))unsigned int lin)
{
	int asci;
	stack_t *tmpo;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmpo = *stack;
	while (tmpo != NULL)
	{
		asci = tmpo->n;
		if (asci <= 0 || asci > 127)
			break;
		printf("%c", asci);
		tmpo = tmpo->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin: Interger representing the line number of of the opcode.
*/

void rotl(stack_t **stack, __attribute__((unused))unsigned int lin)
{
	stack_t *tmpo;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmpo = *stack;
	while (tmpo->next != NULL)
		tmpo = tmpo->next;

	tmpo->next = *stack;
	(*stack)->prev = tmpo;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lin: Interger representing the line number of of the opcode.
*/

void rotr(stack_t **stack, __attribute__((unused))unsigned int lin)
{
	stack_t *tmpo;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmpo = *stack;

	while (tmpo->next != NULL)
		tmpo = tmpo->next;

	tmpo->next = *stack;
	tmpo->prev->next = NULL;
	tmpo->prev = NULL;
	(*stack)->prev = tmpo;
	(*stack) = tmpo;
}
