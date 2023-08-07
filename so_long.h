/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:55:12 by yachen            #+#    #+#             */
/*   Updated: 2023/08/07 16:08:32 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TS 25
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include "./mlx_linux/mlx_int.h"

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_content
{
	int	c;
	int	e;
	int	p;
}		t_content;

typedef struct s_data
{
	void	*img;
	char	*adr;
	int		width;
	int		height;
	int		bpp;
	int		l;
	int		edn;
}			t_data;

typedef struct s_map_info
{
	char	**map;
	void	*mlx;
	void	*mlx_w;
	t_data	*wall;
	t_data	*ply_back;
	t_data	*ply_front;
	t_data	*ply_left;
	t_data	*ply_right;
	t_data	*coin;
	t_data	*floor;
	t_data	*exit;
}			t_map_info;

typedef struct s_enmy
{
	t_data	*pos1;
	t_data	*pos2;
}			t_enmy;
// utils 1
void		free_tab(char **tab);
int			count_coin(char **map);
int			count_str(char *argv);
char		**make_map(char **argv);
t_point		find_map_size(char **map);
// utils 2
void		ft_check_content(char **map);
void		check_content(char **map);
void		find_p(char **map, t_point *p);
void		check_coin(char **map, t_point size, int y, int x);
int			check_coin2(char **map);
// utils 3
int			check_exit(char **map, t_point size, int y, int x);
int			ft_check_wall(char **map, t_point size);
void		ft_error2(char **map);
void		ft_error1(char **map);
void		ft_init(t_content *cnt);
//utils 4
int			check_map_name(char **argv);
t_data		*load_img(void *mlx, char *path);
t_map_info	*ft_clean(t_map_info *map_info);
void		draw_img(t_map_info *map_info, t_data *img, int i, int j);
void		load_map(t_map_info *map_info);
// utils 5
int			ft_strlen2(char *str);

void		map_parsing(char **argv);
t_map_info	*map_init(char **argv);
void		map_display(t_map_info *map_info);
int			mouse_hook(t_map_info *map_info);
int			key_hook(int keysym, t_map_info *map_info);

#endif
