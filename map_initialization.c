/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:43:54 by yachen            #+#    #+#             */
/*   Updated: 2023/08/08 15:40:39 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_init_1(t_map_info *map_info)
{
	map_info->map = NULL;
	map_info->mlx = NULL;
	map_info->mlx_w = NULL;
	map_info->wall = NULL;
	map_info->ply_back = NULL;
	map_info->ply_front = NULL;
	map_info->ply_left = NULL;
	map_info->ply_right = NULL;
	map_info->coin = NULL;
	map_info->floor = NULL;
	map_info->exit = NULL;
}

static int	map_init_2(t_map_info *map_info)
{
	map_info->wall = load_img(map_info->mlx, "./map_img/tree.xpm");
	map_info->ply_back = load_img(map_info->mlx, "./map_img/ply_back.xpm");
	map_info->ply_front = load_img(map_info->mlx, "./map_img/ply_front.xpm");
	map_info->ply_left = load_img(map_info->mlx, "./map_img/ply_left.xpm");
	map_info->ply_right = load_img(map_info->mlx, "./map_img/ply_right.xpm");
	map_info->coin = load_img(map_info->mlx, "./map_img/coin.xpm");
	map_info->floor = load_img(map_info->mlx, "./map_img/floor.xpm");
	map_info->exit = load_img(map_info->mlx, "./map_img/exit.xpm");
	if (!map_info->wall || !map_info->ply_back || !map_info->ply_front
		|| !map_info->ply_left || !map_info->ply_right || !map_info->coin
		|| !map_info->coin || !map_info->floor || !map_info->exit)
		return (0);
	return (1);
}

t_map_info	*map_init(char **argv)
{
	t_map_info	*map_info;
	t_point		ms;

	ms.y = 0;
	ms.x = 0;
	map_info = malloc(sizeof(t_map_info));
	if (!map_info)
		return (NULL);
	map_init_1(map_info);
	map_info->map = make_map(argv);
	if (!map_info->map)
		return (ft_clean(map_info));
	ms = find_map_size(map_info->map);
	ms.y *= TS;
	ms.x *= TS;
	map_info->mlx = mlx_init();
	if (!map_info->mlx)
		return (ft_clean(map_info));
	map_info->mlx_w = mlx_new_window(map_info->mlx, ms.x, ms.y, "Window");
	if (!map_info->mlx_w)
		return (ft_clean(map_info));
	if (map_init_2(map_info) == 0)
		return (ft_clean(map_info));
	return (map_info);
}
