/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:33:10 by vcharbon          #+#    #+#             */
/*   Updated: 2016/11/27 15:00:55 by vcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		*create_tet(char *buf, int oct, char *checkfile);
int		*import_file(char **av);
int		main(int ac, char **av);
int		calc_len_line_grid(int increase_sizegrid, int size_tetlist);
char	*grid_structure(int increase_sizegrid, int sizegrid);
char	*backtrack(int sizetetlist, int tetnbr, char *grid, int len_line_grid);
int		ft_sqrt(int nb);
void	ft_putstr(char *s);
int		ft_memcmp(void *s1, void *s2, size_t num);
size_t	ft_strlen(char *str);
char	*ft_strnstr(char *big, char *lit, size_t len);
char	*ft_strstr(char *big, char *lit);
int		ft_atoi(char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strnew(int size);
char	*ft_strncpy(char *dest, char *src, int num);
int		*do_shit(int ac, char **av);
int		*bitch(char *buf, int *octn, char *checkfile);
char	check_tetriminos_position(int tetnbr, char *grid,
	int len_line_grid, int position);
void	truc(int *posn, int tetnbr, char *grid);
void	truc2(int *posn, int tetnbr, char *grid);

int		*g_tetlist;

#endif
