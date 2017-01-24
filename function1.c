/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:31:15 by vcharbon          #+#    #+#             */
/*   Updated: 2016/11/27 14:26:03 by vcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_memcmp(void *s1, void *s2, size_t num)
{
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char*)s1;
	t2 = (unsigned char*)s2;
	while (num > 0)
	{
		if (*t1 != *t2)
			return (*t1 - *t2);
		num--;
		t1++;
		t2++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

char	*ft_strnstr(char *big, char *lit, size_t len)
{
	size_t n;

	if (!*lit)
		return ((char *)big);
	while (*big && len >= ft_strlen(lit))
	{
		n = 0;
		if (ft_memcmp(big, lit, ft_strlen(lit)) == 0)
			return ((char *)big);
		len--;
		big++;
	}
	return (NULL);
}

char	*ft_strstr(char *big, char *lit)
{
	return (ft_strnstr(big, lit, ft_strlen(big)));
}

int		ft_atoi(char *s)
{
	int ret;
	int neg;

	ret = 0;
	neg = 1;
	while ((*s == ' ') || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-')
	{
		neg = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s && *s >= '0' && *s <= '9')
	{
		ret = ret * 10 + *s - '0';
		s++;
	}
	return (ret * neg);
}
