/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnolan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:33:49 by lnolan            #+#    #+#             */
/*   Updated: 2018/12/13 16:39:34 by lnolan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int min, int max)
{
	int *str;
	int	i;

	i = 0;
	if (min >= max)
	{
		return (NULL);
	}
	else
	{
		str = (int *)malloc((max - min) * sizeof(int));
		while (min < max)
		{
			str[i++] = min;
			min++;
		}
	}
	return (str);
}
