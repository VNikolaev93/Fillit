/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnolan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:28:25 by lnolan            #+#    #+#             */
/*   Updated: 2018/12/13 18:53:01 by lnolan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*k1;
	unsigned char	*k2;

	i = 0;
	k1 = (unsigned char *)s1;
	k2 = (unsigned char *)s2;
	if (n == 0 || n == (size_t)-1)
		return (0);
	if (n > 0)
	{
		while (i < n && (k1[i] == k2[i]) && k1[i])
			i++;
		if (i == n)
			return (k1[i - 1] - k2[i - 1]);
	}
	return (k1[i] - k2[i]);
}
