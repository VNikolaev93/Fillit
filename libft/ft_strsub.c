/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnolan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:06:59 by lnolan            #+#    #+#             */
/*   Updated: 2018/12/09 20:31:18 by lnolan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	ns = ft_strnew(len);
	if (!ns)
		return (NULL);
	while (i < len)
		*(ns + i++) = *(s + start++);
	return (ns);
}
