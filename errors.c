#include "monty.h"

/**
 * error - Prints appropiate error messages determined by their error code.
 * @eror_cde: The error codes are the following:
 * (1) => user does not give any file or more than one file to the program.
 * (2) => file provided is not a file that can be opened or read.
 * (3) => file provided contains an invalid instruction.
 * (4) => When program is unable to malloc more memory.
 * (5) => When parameter passed to the instruction "push" is not an int.
 * (6) => When stack it empty for pint.
 * (7) => When stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void error(int eror_cde, ...)
{
	va_list aga;
	char *ope;
	int li_num;

	va_start(aga, eror_cde);
	switch (eror_cde)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(aga, char *));
			break;
		case 3:
			li_num = va_arg(aga, int);
			ope = va_arg(aga, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", li_num, ope);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(aga, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_error - handles errors.
 * @eror_cde: The error codes are the following:
 * (6) => When stack it empty for pint.
 * (7) => When stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
*/

void more_error(int eror_cde, ...)
{
	va_list aga;
	char *ope;
	int li_num;

	va_start(aga, eror_cde);
	switch (eror_cde)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(aga, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(aga, int));
			break;
		case 8:
			li_num = va_arg(aga, unsigned int);
			ope = va_arg(aga, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", li_num, ope);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(aga, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_error - handles errors.
 * @eror_cde: error codes are the following:
 * (10) ~> number inside a node is outside ASCII bounds.
 * (11) ~> stack is empty.
*/

void string_error(int eror_cde, ...)
{
	va_list aga;
	int li_num;

	va_start(aga, eror_cde);
	li_num = va_arg(aga, int);
	switch (eror_cde)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", li_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", li_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
