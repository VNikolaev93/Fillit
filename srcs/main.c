/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnolan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:23:47 by lnolan            #+#    #+#             */
/*   Updated: 2019/01/24 23:01:40 by lnolan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

t_xy				*get_xy(const char *str, int j, int x, int i)
{
	int		y;
	t_xy	*tmp;

	tmp = (t_xy *)malloc(sizeof(t_xy));
	y = 0;
	while (str[i] != '\0')
	{
		if (i == 4 || i == 9 || i == 14 || i == 19)
		{
			x = -1;
			y++;
		}
		if (str[i] == '#')
		{
			tmp->x[j] = x;
			tmp->y[j++] = y;
		}
		i++;
		x++;
	}
	return (tmp);
}

t_figure			*save_tetr(const char *str, int name)
{
	t_figure		*tmp;
	int				i;
	int				x;
	int				j;
	t_xy			*xy;

	tmp = (t_figure *)malloc(sizeof(t_figure));
	x = 0;
	j = 0;
	i = 0;
	xy = get_xy(str, j, x, i);
	while (i < 4)
	{
		tmp->x[i] = xy->x[i];
		tmp->y[i] = xy->y[i];
		i++;
	}
	tmp->width = (-1) * (0 - ft_max(tmp->x, 4));
	tmp->height = (-1) * (0 - ft_max(tmp->y, 4));
	tmp->name = name + 65;
	return (tmp);
}

void				xynull(t_figure **tetrim, int j)
{
	int i;
	int f;
	int u;
	int k;

	i = 0;
	k = 0;
	while (i <= j)
	{
		f = (0 - ft_min(tetrim[i]->x, 4));
		u = (0 - ft_min(tetrim[i]->y, 4));
		k = 0;
		while (k < 4)
		{
			tetrim[i]->x[k] = tetrim[i]->x[k] + f;
			tetrim[i]->y[k] = tetrim[i]->y[k] + u;
			k++;
		}
		i++;
	}
}

int					main(int ac, char **av)
{
	int			n;
	t_figure	**tetrim;
	int			fd;
	char		*line;

	tetrim = (t_figure **)malloc(sizeof(t_figure *) * 26);
	n = 0;
	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		print_usage();
	else if (ac == 2)
	{
		check_fd(fd);
		while (get_next_figure(fd, &line) == 1 && n < 26)
		{
			tetrim[n] = save_tetr(line, n);
			n++;
		}
		tetrim[n] = save_tetr(line, n);
		close(fd);
		if (n > 25)
			print_err();
	}
	final_solve(tetrim, n);
	return (0);
}
