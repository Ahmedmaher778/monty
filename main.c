#include "monty.h"

/**
 * main - entry point
 * @argoc: arguments count
 * @argov: list of arguments
 * Return: always 0
*/

int main(int argoc, char *argov[])
{
	if (argoc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argov[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - Creates a node.
 * @num: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
*/

stack_t *create_node(int num)
{
	stack_t *nde;

	nde = malloc(sizeof(stack_t));
	if (nde == NULL)
		err(4);
	nde->next = NULL;
	nde->prev = NULL;
	nde->num = num;
	return (nde);
}

/**
 * free_nodes - Frees nodes in the stack.
*/

void free_nodes(void)
{
	stack_t *tmpo;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmpo = head;
		head = head->next;
		free(tmpo);
	}
}


/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @lin: line number of the opcode.
*/

void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int lin)
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
	while (tmpo->next != NULL)
		tmpo = tmpo->next;

	tmpo->next = *new_node;
	(*new_node)->prev = tmpo;

}
