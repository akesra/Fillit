/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:01:01 by vcharbon          #+#    #+#             */
/*   Updated: 2016/11/27 14:24:53 by vcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	truc(int *posn, int tetnbr, char *grid)
{
	posn[1] = 0;
	while (posn[1] < 4)
	{
		if (g_tetlist[tetnbr * 4 + posn[1]] == 0)
			grid[posn[0]] = '.';
		else
			grid[posn[0] + g_tetlist[tetnbr * 4 + posn[1]] / 4 * posn[2]
				+ g_tetlist[tetnbr * 4 + posn[1]] % 4] = '.';
		posn[1]++;
	}
}

void	truc2(int *posn, int tetnbr, char *grid)
{
	if (g_tetlist[tetnbr * 4 + posn[1]] == 0)
		grid[posn[0]] = tetnbr + 'A';
	else
		grid[posn[0] + g_tetlist[tetnbr * 4 + posn[1]] / 4 * posn[2]
			+ g_tetlist[tetnbr * 4 + posn[1]] % 4] = tetnbr + 'A';
	posn[1]++;
}

char	*backtrack(int sizetetlist, int tetnbr, char *grid, int len_line_grid)
{
	int posn[3];

	posn[0] = 0;
	posn[2] = len_line_grid;
	if (!(grid))
		return (grid);
	if (tetnbr == sizetetlist / 4)
		return (grid);
	while (grid[posn[0]])
	{
		if (check_tetriminos_position(tetnbr, grid, len_line_grid, posn[0]))
		{
			posn[1] = 0;
			while (posn[1] < 4)
				truc2(posn, tetnbr, grid);
			if (backtrack(sizetetlist, tetnbr + 1, grid, len_line_grid))
				return (grid);
			else
				truc(posn, tetnbr, grid);
		}
		posn[0]++;
	}
	return (NULL);
}
