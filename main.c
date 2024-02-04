#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *cont;
	FILE *f;
	size_t s = 0;
	ssize_t rl = 1;
	stack_t *sk = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	bus.file = f;
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (rl > 0)
	{
		cont = NULL;
		rl = getline(&cont, &s, f);
		bus.content = cont;
		count++;
		if (rl > 0)
		{
			execute(cont, &sk, count, f);
		}
		free(cont);
	}
	free_stack(sk);
	fclose(f);
return (0);
}
