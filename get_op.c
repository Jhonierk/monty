#include "monty.h"
/**
 * get_op - obtains the function to operate.
 * @argv: string with command
 * Return: function.
 */
void (*get_op(char **argv))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (ops[i].opcode)
	{
		if (strcmp(argv[0], ops[i].opcode) == 0)
		{
			if (strcmp(argv[0], "push") == 0 && atoi(argv[1]) != 0)
				return (ops[i].f);
			else if (strcmp(argv[0], "push") == 0 && argv[1][0] == '0')
				return (ops[i].f);
			else if (strcmp(argv[0], "push") != 0)
				return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
