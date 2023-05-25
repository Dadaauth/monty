#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "monty.h"
/**
 * openFile - a function to do the work of opening files
 * @filepath: the path to the file to open
 * Return: a pointer to the opened file
 */
FILE *openFile(char *filepath)
{
	UNUSED char *err_str;
	/* the filepath is already defined globally */
	fp = fopen(filepath, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filepath);
		exit(EXIT_FAILURE);
	}
	return (fp);
}
/**
 * clearWhiteSpaceAndTab - clears whitespace and tabs from
 * a string
 * @str: the string.
 */
void clearWhiteSpaceAndTab(char *str)
{
	int length = strlen(str);
	int i = 0;

	/**
	 * printf("\n---------------------------\n");
	 * printf("\n\nlength 1 => %d\n", length);
	 * printf("Str before action => %s\n", str);
	*/
	while (isspace(str[i]) && i < length)
	{
		i++;
	}
	memmove(str, str + i, length - i + 1);
	/**
	 * printf("Str after first action %s\n", str);
	 * printf("length 2 = %ld\n", strlen(str));
	*/
	i = strlen(str) - 1;
	while (isspace(str[i]))
	{
		str[i] = '\0';
		i--;
	}
	/**
	 * printf("String at last => %s\n\n\n", str);
	 * printf("-----------------------------\n\n");
	*/
}
/**
 * isStringInt - checks if a string contains only digits
 * @str: the string to test
 * Return: true or false.
 */
bool isStringInt(const char *str)
{
	char start = str[0];

	while (*str != '\0')
	{
		if (!isdigit(*str) && start != '-')
			return (false);
		str++;
	}
	return (true);
}
