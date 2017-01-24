/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:58:04 by vcharbon          #+#    #+#             */
/*   Updated: 2016/11/27 14:28:22 by vcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int n;

	n = 0;
	while (s[n])
	{
		ft_putchar_fd(s[n], fd);
		n++;
	}
}

void	ft_putstr(char *s)
{
	ft_putstr_fd(s, 1);
}

int		ft_sqrt(int nb)
{
	int	r;
	int	i;

	i = 0;
	r = 1;
	while (r <= nb / 2)
	{
		i = r * r;
		if (i == nb)
			return (r);
		r++;
	}
	return (0);
}

char	*ft_strnew(int size)
{
	char	*str;
	int		n;

	n = 0;
	if (!(str = (char *)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	else
	{
		while (n < size + 1)
		{
			str[n] = '\0';
			n++;
		}
		return (str);
	}
}
