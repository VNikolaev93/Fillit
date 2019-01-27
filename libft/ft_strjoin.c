/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnolan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:41:43 by lnolan            #+#    #+#             */
/*   Updated: 2018/12/13 18:56:42 by lnolan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ns;
	size_t	i;
	size_t	j;
	size_t	s1len;
	size_t	s2len;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ns = ft_strnew(s1len + s2len);
	if (!ns)
		return (NULL);
	while (++i < s1len)
		*(ns + i) = *(s1 + i);
	while (++j < s2len)
		*(ns + i++) = *(s2 + j);
	return (ns);
}
