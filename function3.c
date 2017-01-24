/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:58:04 by vcharbon          #+#    #+#             */
/*   Updated: 2016/11/27 14:29:01 by vcharbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strncpy(char *dest, char *src, int num)
{
	int n;

	n = 0;
	while (n < num && src[n])
	{
		dest[n] = src[n];
		n++;
	}
	if (src[n] == '\0')
	{
		while (n < num)
		{
			dest[n] = '\0';
			n++;
		}
	}
	return (dest);
}
