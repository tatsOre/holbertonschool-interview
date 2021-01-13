#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"
/**
 * print_sandpile - Prints 3x3 grid
 * @grid: 3x3 grid
 * Return: Nothing
 */
void print_sandpile(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * unstable_sandpiles - Check if a sandpile is unstable
 * @grid: 3x3 grid sandpile
 * Return: 1 for true | 0 for false
 */
int unstable_sandpiles(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				print_sandpile(grid);
				return (1);
			}
		}
	}
	return (0);
}

/**
 * toppling - Topples sandpiles
 * @grid1: 3x3 grid sandpile No. 1
 * @grid2: 3x3 grid sandpile No. 2
 * Return: nothing
 */
void toppling(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid2[i][j] = 0;
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				if (i > 0)
					grid2[i - 1][j] += 1;

				if (i < 2)
					grid2[i + 1][j] += 1;

				if (j < 2)
					grid2[i][j + 1] += 1;

				if (j > 0)
					grid2[i][j - 1] += 1;

				grid1[i][j] -= 4;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * Grid1 must be printed before each toppling round, only if it is unstable
 * @grid1: 3x3 grid sandpile No. 1
 * @grid2: 3x3 grid sandpile No. 2
 * Return: nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}
	i = 1;
	while (i)
	{
		i = unstable_sandpiles(grid1);
		toppling(grid1, grid2);
	}
}
