/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnolan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:23:36 by lnolan            #+#    #+#             */
/*   Updated: 2019/01/24 23:21:20 by lnolan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		*ft_get_ln(char **curr_data)
{
	char				*res;
	char				*temp;
	size_t				i;

	i = 0;
	if (!(temp = ft_strdup(*curr_data)))
		return (NULL);
	while (i < 21 && temp[i])
		i++;
	if (!(res = ft_strnew(i)))
		return (NULL);
	ft_strncpy(res, *curr_data, i);
	ft_strdel(curr_data);
	if (i < ft_strlen(temp))
	{
		if (!(*curr_data = ft_strdup(temp + i + 1)))
			return (NULL);
	}
	else
	{
		if (!(*curr_data = ft_strdup("\0")))
			return (NULL);
	}
	ft_strdel(&temp);
	return (res);
}

char		*ft_strjoinfree(char **curr_data, char *buff)
{
	char				*res;
	size_t				i;

	i = ft_strlen(*curr_data) + ft_strlen(buff);
	if (!(res = ft_strnew(i)))
		return (NULL);
	ft_strcpy(res, *curr_data);
	ft_strcat(res, buff);
	ft_strdel(curr_data);
	return (res);
}

char		*ft_strbknn(char *s)
{
	int i;
	int j;

	i = -1;
	j = (int)(ft_strlen(s) + 1);
	while (++i < (j))
		if (s[i] == '\n' && s[i + 1] == '\n')
			return (s + i + 1);
	return (NULL);
}

int			get_next_figure(int fd, char **line)
{
	char			buff[B_S + 1];
	static t_line	*file;
	int				ret;
	t_line			*curr;

	if (fd < 0 || !line || !(curr = c_f(&file, fd)) || read(fd, buff, 0) < 0)
		return (-1);
	ret = 0;
	while (!(ft_strbknn(curr->data)) && ((ret = read(fd, buff, B_S)) == 21))
	{
		buff[ret] = '\0';
		(!(curr->data = ft_strjoinfree(&curr->data, buff))) ? (-1) : norm();
		!(v_c(buff)) || !(v_f(buff)) ? print_err() : ft_strbknn(curr->data);
	}
	if (ret == 20)
	{
		if (!(curr->data = ft_strjoinfree(&curr->data, buff)))
			return (-1);
		!(v_c(buff)) || !(v_f(buff)) ? print_err() : norm();
		if (!(*line = ft_get_ln(&curr->data)))
			return (-1);
		return (0);
	}
	(!(*line = ft_get_ln(&curr->data))) ? (-1) : norm();
	return (1);
}
