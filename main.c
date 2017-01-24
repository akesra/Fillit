/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:39:09 by vcharbon          #+#    #+#             */
/*   Updated: 2016/12/21 12:01:43 by akesraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*bitch(char *buf, int *octn, char *checkfile)
{
	char	*tet;

	tet = ft_strnew(21);
	if (!(ft_strstr(checkfile, ft_strncpy(tet, buf, 21))))
		return (NULL);
	while ((octn[1] + 1) % 4 != 0 || octn[1] == 0)
	{
		g_tetlist[octn[1]] = *(ft_strstr(checkfile, ft_strncpy(tet, buf, 21))
				+ 21 + octn[1] % 4) - '0';
		octn[1]++;
	}
	if ((octn[0] + 1) / 21 * 4 - 1 == octn[1])
	{
		g_tetlist[octn[1]] = ft_atoi(ft_strstr(checkfile,
					ft_strncpy(tet, buf, 20)) + 21 + octn[1] % 4);
		g_tetlist[octn[1] + 1] = 69;
	}
	else
	{
		g_tetlist[octn[1]] = ft_atoi(ft_strstr(checkfile,
					ft_strncpy(tet, buf, 21)) + 21 + octn[1] % 4);
		octn[1]++;
	}
	free(tet);
	return (g_tetlist);
}

int		*create_tet(char *buf, int oct, char *checkfile)
{
	int	octn[2];

	octn[0] = oct;
	octn[1] = 0;
	while (*buf)
	{
		if (!(g_tetlist = bitch(buf, octn, checkfile)))
			return (NULL);
		buf = buf + 21;
	}
	return (g_tetlist);
}

int		*import_file(char **av)
{
	int		fd;
	int		oct;
	char	buf[21 * 26 + 1];
	char	*checkfile;

	checkfile = ft_strnew(2915);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (NULL);
	if ((oct = read(fd, buf, 21 * 26)) < 0)
		return (NULL);
	close(fd);
	if (oct % 21 != 20 || oct > 20 * 26)
		return (NULL);
	if ((fd = open("extern_file.txt", O_RDONLY)) < 0)
		return (NULL);
	if ((read(fd, checkfile, 2915)) < 0)
		return (NULL);
	if (!(g_tetlist = (int*)malloc(sizeof(*g_tetlist)
					* (oct + 1) / 21 * 4 + 1)))
		return (NULL);
	g_tetlist = create_tet(buf, oct, checkfile);
	free(checkfile);
	return (g_tetlist);
}

int		*do_shit(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (0);
	}
	if (!(g_tetlist = import_file(av)))
	{
		ft_putstr("error\n");
		return (0);
	}
	return (g_tetlist);
}

int		main(int ac, char **av)
{
	char	*grid;
	int		sizetetlist;
	int		increase_sizegrid;

	g_tetlist = NULL;
	increase_sizegrid = 0;
	sizetetlist = 0;
	if (!(g_tetlist = do_shit(ac, av)))
		return (0);
	while (g_tetlist[sizetetlist] != 69)
		sizetetlist++;
	if (!(grid = grid_structure(increase_sizegrid, sizetetlist)))
		return (0);
	while (!(grid = backtrack(sizetetlist, 0, grid,
					calc_len_line_grid(increase_sizegrid, sizetetlist))))
	{
		increase_sizegrid++;
		free(grid);
		if (!(grid = grid_structure(increase_sizegrid, sizetetlist)))
			return (0);
	}
	ft_putstr(grid);
	free(g_tetlist);
	return (0);
}
