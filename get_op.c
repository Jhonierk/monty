#include "monty.h"
/**
 * get_op - obtains the function to operate.
 * @str: string with command
 * Return: function.
 */
void (*get_op(char *str))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", _push},
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (ops[i].opcode)
	{
		if (strcmp(str, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
