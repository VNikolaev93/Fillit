/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnolan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:26:34 by lnolan            #+#    #+#             */
/*   Updated: 2018/12/13 16:37:07 by lnolan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(int *tab, size_t len)
{
	int min;

	if (!len)
		return (0);
	min = tab[--len];
	while (len--)
		if (tab[len] < min)
			min = tab[len];
	return (min);
}
