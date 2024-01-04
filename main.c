#include "monty.h"

/**
 * main - Entry point.
 *
 * @argc: Numbers of the program arguments.
 * @argv: Array of string of the program arguments.
 *
 * Return: Always 0.
*/
stack_t *head_stack = NULL;
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char *line = NULL, *token_line = NULL, *check_instruction = NULL;
	unsigned int max_len_line = 1024, line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE); }
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		fclose(file);
		exit(EXIT_FAILURE); }
	line = malloc(sizeof(char) * max_len_line);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(line);
		fclose(file);
		exit(EXIT_FAILURE); }
	while (fgets(line, max_len_line, file))
	{
		token_line = strtok(line, "\n");
		check_instruction = is_instruction(token_line, line_number);
		if (check_instruction != NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, check_instruction);
			free_stack(head_stack);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE); }
		line_number++; }
	free_stack(head_stack);
	free(line);
	fclose(file);
	return (0);
}
