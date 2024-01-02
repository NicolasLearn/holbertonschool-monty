#include "monty.h"

/**
 * main - Entry point.
 *
 * @argc: Numbers of the program arguments.
 * @argv: Array of string of the program arguments.
 *
 * Return: Always 0.
*/
int main (int argc, char *argv[])
{
	FILE *file = NULL;
	char *line = NULL, *token_line = NULL;
	int max_len_line = 1024, line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line = malloc(sizeof (char) * max_len_line);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (fgets(line, max_len_line, file))
	{
		printf("Line : <%d>. Sentence : %s", line_number, line);
		token_line = strtok(line, "\n");
		token_line = strtok(token_line, " ");
		while (token_line != NULL)
		{
			printf("Token = <%s>\n", token_line);
			token_line = strtok(NULL, " ");
		}
		putchar('\n');
		line_number++;
	}
	free(line);
	fclose(file);
	return (0);
}

/**
 * compilation : gcc -Wall -Werror -Wextra -pedantic *.c -o monty
 * execution : ./monty test/monty_test.m
*/
