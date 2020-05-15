#include "monty.h"
/**
 * main - main function of simple interpreter of stack
 *        and queue
 * @av: arguments vector
 * @ac: arguments counter
 * Return: 0 = success
 */
int main(int ac, char **av)
{
	char *buffer = NULL; 
	size_t buffsize;
	FILE *fd;
	int n, i = 0;

	if (ac == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", av[1]);
		exit(EXIT_FAILURE);
	}
	while((n = getline(&buffer, &buffsize, fd)) != -1)
	{
		command(buffer, n);
		i++;
	}
	fflush(fd);
	fclose(fd);
	free(buffer);
	return (0);
}

/**
 * command - function to tokenize buffer
 * @buffer: line to be tokenized
 * Return: array with every word
 */
char **command(char *buffer, int word_counter)
{
	char **array;
	char *token = NULL;
	int i = 0;

	array = malloc(sizeof(char) * word_counter);
	if (array == NULL)
	{
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, " \n");
	while (token)
	{
		printf("%s\n", token);
		array[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	return (array);
}