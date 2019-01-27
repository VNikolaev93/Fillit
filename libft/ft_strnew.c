/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnolan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:26:38 by lnolan            #+#    #+#             */
/*   Updated: 2018/12/13 18:58:17 by lnolan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *sn;

	if (size == (size_t)-1)
		return (NULL);
	sn = (char *)malloc(sizeof(char) * size + 1);
	if (!sn)
		return (NULL);
	ft_bzero(sn, size + 1);
	return (sn);
}
