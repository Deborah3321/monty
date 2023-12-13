#include "monty.h"

/**
 * op_div - divides the second top element of the stack by the top element
 * @stack: double pointer to the head of the stack
 * @line_number: current line number in the file
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int outcome;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	outcome = temp->next->n / temp->n;
	temp->next->n = outcome;
	*stack = temp->next;
	free(temp);
}
