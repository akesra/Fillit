/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:39:34 by vcharbon          #+#    #+#             */
/*   Updated: 2016/11/27 14:20:27 by vcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	check_tetriminos_position(int tetnbr, char *grid,
		int len_line_grid, int position)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (j < 4 && count == j)
	{
		if (g_tetlist[tetnbr * 4 + j] == 0 && grid[position] == '.')
			count++;
		else if (grid[position + g_tetlist[tetnbr * 4 + j] / 4 *
				len_line_grid + g_tetlist[tetnbr * 4 + j] % 4] == '.')
			count++;
		j++;
	}
	if (count == j)
		return (1);
	else
		return (0);
}

int		calc_len_line_grid(int increase_sizegrid, int size_tetlist)
{
	int sizegrid;

	sizegrid = size_tetlist;
	while (ft_sqrt(sizegrid) == 0)
		sizegrid++;
	return (ft_sqrt(sizegrid) + increase_sizegrid + 1);
}

char	*grid_structure(int increase_sizegrid, int sizegrid)
{
	char	*grid;
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (ft_sqrt(sizegrid) == 0)
		sizegrid++;
	sizegrid = (ft_sqrt(sizegrid) + increase_sizegrid) * (ft_sqrt(sizegrid)
			+ increase_sizegrid);
	if (!(grid = ft_strnew(sizegrid + ft_sqrt(sizegrid))))
		return (NULL);
	while (count < ft_sqrt(sizegrid))
	{
		if ((i + 1) % (ft_sqrt(sizegrid) + 1) == 0)
		{
			grid[i] = '\n';
			count++;
			if (count == ft_sqrt(sizegrid))
				return (grid);
			i++;
		}
		grid[i++] = '.';
	}
	return (grid);
}
