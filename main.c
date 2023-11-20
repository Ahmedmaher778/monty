#include "monty.h"

/**
 * open_file - opens a file
 * @fle_name: file namepath
 * Return: void
*/

void open_file(char *fle_name)
{
	FILE *fdb = fopen(fle_name, "r");

	if (fle_name == NULL || fdb == NULL)
		err(2, fle_name);

	read_file(fdb);
	fclose(fdb);
}


/**
 * read_file - reads a file
 * @fdb: pointer to file descriptor
 * Return: void
*/

void read_file(FILE *fdb)
{
	int lin_nmber, format = 0;
	char *bufer = NULL;
	size_t leng = 0;

	for (lin_nmber = 1; getline(&bufer, &leng, fdb) != -1; lin_nmber++)
	{
		format = parse_line(bufer, lin_nmber, format);
	}
	free(bufer);
}


/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @bufer: line from the file
 * @lin_nmber: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
*/

int parse_line(char *bufer, int lin_nmber, int format)
{
	char *opcde, *valu;
	const char *delm = "\n ";

	if (bufer == NULL)
		err(4);

	opcde = strtok(bufer, delm);
	if (opcde == NULL)
		return (format);
	valu = strtok(NULL, delm);

	if (strcmp(opcde, "stack") == 0)
		return (0);
	if (strcmp(opcde, "queue") == 0)
		return (1);

	find_func(opcde, valu, lin_nmber, format);
	return (format);
}

/**
 * find_func - find the appropriate function for the opcode
 * @opcde: opcode
 * @valu: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @lin: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
*/

void find_func(char *opcde, char *valu, int lin, int format)
{
	int l;
	int flg;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcde[0] == '#')
		return;

	for (flg = 1, l = 0; func_list[l].opcde != NULL; l++)
	{
		if (strcmp(opcde, func_list[l].opcde) == 0)
		{
			call_fun(func_list[i].f, opcde, valu, lin, format);
			flg = 0;
		}
	}
	if (flg == 1)
		err(3, lin, opcde);
}


/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @ope: string representing the opcode.
 * @valu: string representing a numeric value.
 * @lin: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
*/

void call_fun(op_func func, char *ope, char *valu, int lin, int format)
{
	stack_t *nde;
	int flg;
	int l;

	flg = 1;
	if (strcmp(ope, "push") == 0)
	{
		if (valu != NULL && valu[0] == '-')
		{
			valu = valu + 1;
			flg = -1;
		}
		if (valu == NULL)
			err(5, lin);
		for (l = 0; valu[l] != '\0'; l++)
		{
			if (isdigit(valu[l]) == 0)
				err(5, lin);
		}
		nde = create_node(atoi(valu) * flg);
		if (format == 0)
			func(&nde, lin);
		if (format == 1)
			add_to_queue(&nde, lin);
	}
	else
		func(&head, lin);
}
