/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnolan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:23:23 by lnolan            #+#    #+#             */
/*   Updated: 2019/01/24 23:12:35 by lnolan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int				v_f(const char *str)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			k++;
			if (str[i + 1] == '#')
				j++;
			if (str[i + 5] == '#')
				j++;
		}
		i++;
	}
	if ((j == 4 || j == 3) && k == 4)
		return (1);
	return (0);
}

t_line			*c_f(t_line **file, int fd)
{
	t_line				*tmp;

	tmp = *file;
	if (!(tmp = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	if (!(tmp->data = ft_strnew(0)))
		return (0);
	tmp->fd = fd;
	*file = tmp;
	return (tmp);
}

int				v_c(char *str)
{
	int i;

	i = 0;
	if ((str[19] != '\n') && !(str[20] == '\0' || str[20] == '\n'))
		return (0);
	while (str[i] != '\0')
	{
		if (i == 4 || i == 9 || i == 14 || i == 19)
		{
			if (str[i] != '\n')
				return (0);
			i++;
		}
		if ((str[i] != '.' && str[i] != '#') && (i < 20))
			return (0);
		i++;
	}
	if (i < 20)
		return (0);
	return (1);
}

void			check_fd(int fd)
{
	if (fd <= 0)
		print_usage();
}
