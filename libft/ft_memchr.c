/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnolan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:51:01 by lnolan            #+#    #+#             */
/*   Updated: 2018/12/09 20:52:29 by lnolan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const char		*k;

	i = -1;
	k = (const char *)s;
	while (++i < n)
		if (*(k + i) == (char)c)
			return ((void *)s + i);
	return (NULL);
}
