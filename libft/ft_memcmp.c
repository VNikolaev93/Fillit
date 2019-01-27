/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnolan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:29:01 by lnolan            #+#    #+#             */
/*   Updated: 2018/12/09 20:46:01 by lnolan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*k1;
	unsigned char		*k2;

	i = -1;
	k1 = (unsigned char *)s1;
	k2 = (unsigned char *)s2;
	while (++i < n && k1[i] == k2[i])
		;
	if (i == n)
		return (0);
	return (*(k1 + i) - *(k2 + i));
}
