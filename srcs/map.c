/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnolan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:22:25 by lnolan            #+#    #+#             */
/*   Updated: 2019/01/24 21:18:47 by lnolan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void			freemap(t_map *map)
{
	int i;
	int j;

	i = map->size;
	j = 0;
	while (j < i)
	{
		free(map->str[j]);
		j++;
	}
	map->size = 0;
}

int				ft_quad(int n)
{
	int i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

t_map			*gen_map(t_map **map, int k)
{
	char	**res;
	int		i;
	int		j;
	t_map	*tmp;

	*map = (t_map*)malloc(sizeof(t_map));
	tmp = *map;
	tmp->size = ft_quad(k * 4);
	i = 0;
	res = (char **)malloc(sizeof(char *) * tmp->size + 1);
	while (i < tmp->size)
	{
		res[i] = ft_strnew((size_t)tmp->size + 1);
		j = 0;
		while (j < tmp->size)
		{
			res[i][j] = '.';
			j++;
		}
		res[i][j] = '\n';
		i++;
	}
	tmp->str = res;
	*map = tmp;
	return (tmp);
}

void			print_map(t_map *map)
{
	int i;

	i = 0;
	while (map->str[i])
	{
		ft_putendl(map->str[i]);
		i++;
	}
}
