#include "monty.h"
/**
 * f_swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	int leng = 0, a;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		leng++;
	}
	if (leng < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	a = hd->n;
	hd->n = hd->next->n;
	hd->next->n = a;
}
