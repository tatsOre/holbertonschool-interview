#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in @line
 * @direction: can be either: right or left
 *
 * Return: 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_RIGHT)
	{
		slide_zeroes_left(line, size);
		merge_right(line, size);
		slide_zeroes_left(line, size);
	}

	else if (direction == SLIDE_LEFT)
	{
		slide_zeroes_right(line, size);
		merge_left(line, size);
		slide_zeroes_right(line, size);
	}

	return (1);
}

/**
 * merge_left - Merges numbers starting from the left
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in @line
 */

void merge_left(int *line, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (line[i] == line[i + 1])
		{
			line[i] += line[i  + 1];
			line[i + 1] = 0;
		}
	}
}

/**
 * merge_right - Merges numbers starting from the right
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in @line
 */

void merge_right(int *line, size_t size)
{
	ssize_t i;

	for (i = size - 1; i >= 0 ; i--)
	{
		if (line[i] == line[i - 1])
		{
			line[i] += line[i - 1];
			line[i - 1] = 0;
		}
	}
}

/**
 * slide_zeroes_right - Moves all zeros to the end (right)
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in @line
 */

void slide_zeroes_right(int *line, size_t size)
{
	size_t i, nums = 0, tmp = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] > 0)
		{
			tmp = line[i];
			line[i] = line[nums];
			line[nums] = tmp;
			nums++;
		}
	}
}

/**
 * slide_zeroes_left - Moves all zeros to the start (left)
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in @line
 */

void slide_zeroes_left(int *line, size_t size)
{
	ssize_t i, zeroes = 0;

	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] == 0)
			zeroes++;
		else
			line[i + zeroes] = line[i];
	}
	for (i = 0; i < zeroes; i++)
		line[i] = 0;
}
