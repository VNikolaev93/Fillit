/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnolan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:24:02 by lnolan            #+#    #+#             */
/*   Updated: 2019/01/25 14:15:57 by lnolan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		print_err(void)
{
	write(1, "error\n", 6);
	exit(0);
}

void		print_usage(void)
{
	write(1, "usage: invalid argument\n", 24);
	exit(0);
}

int			norm(void)
{
	return (0);
}
