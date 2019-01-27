/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsharna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:17:23 by lnolan            #+#    #+#             */
/*   Updated: 2019/01/27 19:25:40 by bsharna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include <math.h>

# define B_S 21

typedef struct		s_figure
{
	int				name;
	int				x[4];
	int				y[4];
	int				width;
	int				height;
}					t_figure;

typedef struct		s_line
{
	int				fd;
	char			*data;
}					t_line;

typedef struct		s_map
{
	char			**str;
	int				size;
}					t_map;

typedef struct		s_xy
{
	int				x[4];
	int				y[4];
}					t_xy;

int					norm(void);
void				xynull(t_figure **tetriminos, int j);
t_xy				*get_xy(const char *str, int j, int x, int i);
t_figure			*save_tetr(const char *str, int name);
char				*ft_strjoinfree(char **curr_data, char *buff);
char				*ft_get_ln(char **curr_data);
int					get_next_figure(int fd, char **line);
char				*ft_strbknn(char *s);
void				print_err();
void				print_usage(void);
int					v_f(const char *str);
t_line				*c_f(t_line **file, int fd);
int					v_c(char *str);
void				check_fd(int fd);
void				remove_fig(int i, int k, t_map **map, t_figure *tetrim);
void				place_fig(int i, int k, t_map **map, t_figure *tetrim);
int					check_place(int i, int k, t_map **map, t_figure *tetrim);
int					solving(t_figure **tetrim, t_map *map, int abc, int k);
void				final_solve(t_figure **tetrim, int k);
t_map				*gen_map(t_map **map, int k);
void				print_map(t_map *map);
int					ft_quad(int n);
void				freemap(t_map *map);

#endif
