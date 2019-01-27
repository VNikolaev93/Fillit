/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnolan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:55:56 by lnolan            #+#    #+#             */
/*   Updated: 2018/12/09 20:40:18 by lnolan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*k1;
	unsigned char	*k2;

	i = 0;
	k1 = (unsigned char *)s1;
	k2 = (unsigned char *)s2;
	while (k1[i] == k2[i] && k1[i])
		i++;
	return (k1[i] - k2[i]);
}
