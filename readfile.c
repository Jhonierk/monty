#include "monty.h"
/**
 * readfile - Open a file
 * @file: file.
 */
void readfile(char *file)
{
	FILE *fd;
	char *str = NULL, **argv = NULL;
	size_t size = 0;
	ssize_t line_length;
	stack_t *stack = NULL;
	unsigned int numberl = 1;
	void (*op_fun)(stack_t **stack, unsigned int line_number);

	fd = fopen(file, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	line_length = getline(&str, &size, fd);
	while (line_length != EOF)
	{
		argv = get_string(str);
		op_fun = get_op(argv[0]);
		if (op_fun)
			op_fun(&stack, numberl);
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", numberl, argv[0]);
			exit(EXIT_FAILURE);
		}
		numberl++;
		line_length = getline(&str, &size, fd);
	}
	free(str);
	free(argv);
	fclose(fd);
}
