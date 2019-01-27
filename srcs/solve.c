/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnolan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:22:54 by lnolan            #+#    #+#             */
/*   Updated: 2019/01/24 23:01:17 by lnolan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void			remove_fig(int i, int k, t_map **map, t_figure *tetrim)
{
	int		count;
	t_map	*tmp;

	tmp = *map;
	count = 4;
	while (count--)
		tmp->str[tetrim->y[count] + i][tetrim->x[count] + k] = '.';
}

void			place_fig(int i, int k, t_map **map, t_figure *tetrim)
{
	int		count;
	t_map	*tmp;

	tmp = *map;
	count = 4;
	while (count--)
		tmp->str[tetrim->y[count] + i][tetrim->x[count] + k] = tetrim->name;
}

int				check_place(int i, int k, t_map **map, t_figure *tetrim)
{
	int			count;
	t_map		*tmp;

	tmp = *map;
	count = 4;
	while (count--)
		if (i + tetrim->y[count] >= tmp->size ||
				k + tetrim->x[count] >= tmp->size)
			return (1);
	count = 4;
	while (count--)
		if (tmp->str[tetrim->y[count] + i][tetrim->x[count] + k] != '.')
			return (1);
	return (0);
}

int				solving(t_figure **tetrim, t_map *map, int abc, int k)
{
	int i;
	int j;

	i = 0;
	while (i + tetrim[abc]->height <= map->size + 2)
	{
		j = 0;
		while (j + tetrim[abc]->width <= map->size + 2)
		{
			if (!check_place(i, j, &map, tetrim[abc]))
			{
				place_fig(i, j, &map, tetrim[abc]);
				if ((abc == k) || (solving(tetrim, map, abc + 1, k)))
					return (1);
				else
					remove_fig(i, j, &map, tetrim[abc]);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void			final_solve(t_figure **tetrim, int k)
{
	t_map	*map;
	int		abc;
	int		s;

	xynull(tetrim, k);
	s = k;
	map = gen_map(&map, k);
	abc = 0;
	while (!solving(tetrim, map, abc, k))
	{
		freemap(map);
		s++;
		map = gen_map(&map, s);
	}
	print_map(map);
	freemap(map);
}
