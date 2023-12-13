#include "monty.h"

/**
 * difference - subtracts the top element of the stack from the second top element
 * @stack: double pointer to the head of the stack
 * @line_number: current line number in the file
 */
void difference(stack_t **stack, unsigned int line_number)
{
	int outcome;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	outcome = temp->next->n - temp->n;
	temp->next->n = outcome;
	*stack = temp->next;
	free(temp);
}
