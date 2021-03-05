#include "menger.h"

/**
 * fill - Verifies if one 'cell' should be filled or not.
 *
 * @row:  position x
 * @col:  position y
 *
 * Return: 1 to fill | 0 to keep empty
 */
int fill(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (0);
		row /= 3;
		col /= 3;
	}
	return (1);
}
/**
 * menger - Draws a 2D Menger Sponge, Sierpiński carpet.
 *
 * @level:  level of the Menger Sponge to draw
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
void menger(int level)
{
	int n, row, col;

	n = pow(3, level);
	for (row = 0; row < n; row++)
	{
		for (col = 0; col < n; col++)
		{
			if (fill(row, col))
				putchar('#');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}
