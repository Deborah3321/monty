#include "monty.h"

/**
 * modulus - computes the modulus of the second top element of the stack
 *          with the top element of the stack.
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 */
void modulus(stack_t **stack, unsigned int line_number)
{
	int x, y;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	x = (*stack)->n;
	y = (*stack)->next->n;

	if (x == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = y % x;
	pop(stack, line_number);
}
