/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnolan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:19:31 by lnolan            #+#    #+#             */
/*   Updated: 2018/12/12 22:01:14 by lnolan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	gslen(int x)
{
	size_t			i;

	i = 1;
	while (x /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*s;
	unsigned int	ncp;
	size_t			slen;

	slen = gslen(n);
	ncp = n;
	if (n < 0)
	{
		slen++;
		ncp = -n;
	}
	if (!(s = ft_strnew(slen)))
		return (NULL);
	s[--slen] = ncp % 10 + '0';
	while (ncp /= 10)
		s[--slen] = ncp % 10 + '0';
	if (n < 0)
		*(s + 0) = '-';
	return (s);
}
