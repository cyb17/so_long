/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:17:22 by yachen            #+#    #+#             */
/*   Updated: 2023/08/07 16:48:23 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*static void	print_map(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		i++;
	}
}*/

static void	ft_xk_a(t_map_info *map_info, int *mv)
{
	t_point	p;
	char	**map;

	map = map_info->map;
	find_p(map, &p);
	if (map[p.y][p.x - 1] == 'C' || map[p.y][p.x - 1] == '0')
	{
		ft_printf("%d\n", ++(*mv));
		draw_img(map_info, map_info->ply_left, p.y, p.x - 1);
		draw_img(map_info, map_info->floor, p.y, p.x);
		map[p.y][p.x] = '0';
		map[p.y][p.x - 1] = 'P';
	}
	else if (map[p.y][p.x - 1] == 'E' && count_coin(map) == 0)
	{
		draw_img(map_info, map_info->ply_left, p.y, p.x - 1);
		draw_img(map_info, map_info->floor, p.y, p.x);
		ft_clean(map_info);
		ft_printf("%d\n", ++(*mv));
		ft_printf("Congratulations you have collected all coins!");
		exit(0);
	}
}

static void	ft_xk_d(t_map_info *map_info, int *mv)
{
	t_point	p;
	char	**map;

	map = map_info->map;
	find_p(map_info->map, &p);
	if (map[p.y][p.x + 1] == 'C' || map[p.y][p.x + 1] == '0')
	{
		printf("%d\n", ++(*mv));
		draw_img(map_info, map_info->ply_right, p.y, p.x + 1);
		draw_img(map_info, map_info->floor, p.y, p.x);
		map[p.y][p.x] = '0';
		map[p.y][p.x + 1] = 'P';
	}
	else if (map[p.y][p.x + 1] == 'E' && count_coin(map_info->map) == 0)
	{
		draw_img(map_info, map_info->ply_right, p.y, p.x + 1);
		draw_img(map_info, map_info->floor, p.y, p.x);
		ft_clean(map_info);
		printf("%d\n", ++(*mv));
		ft_printf("Congratulations you have collected all coins!");
		exit(0);
	}
}

static void	ft_xk_w(t_map_info *map_info, int *mv)
{
	t_point	p;
	char	**map;

	map = map_info->map;
	find_p(map_info->map, &p);
	if (map[p.y - 1][p.x] == 'C' || map[p.y - 1][p.x] == '0')
	{
		printf("%d\n", ++(*mv));
		draw_img(map_info, map_info->ply_back, p.y - 1, p.x);
		draw_img(map_info, map_info->floor, p.y, p.x);
		map[p.y][p.x] = '0';
		map[p.y - 1][p.x] = 'P';
	}
	else if (map[p.y - 1][p.x] == 'E' && count_coin(map_info->map) == 0)
	{
		draw_img(map_info, map_info->ply_back, p.y - 1, p.x);
		draw_img(map_info, map_info->floor, p.y, p.x);
		ft_clean(map_info);
		printf("%d\n", ++(*mv));
		ft_printf("Congratulations you have collected all coins!");
		exit(0);
	}
}

static void	ft_xk_s(t_map_info *map_info, int *mv)
{
	t_point	p;
	char	**map;

	map = map_info->map;
	find_p(map_info->map, &p);
	if (map[p.y + 1][p.x] == 'C' || map[p.y + 1][p.x] == '0')
	{
		printf("%d\n", ++(*mv));
		draw_img(map_info, map_info->ply_front, p.y + 1, p.x);
		draw_img(map_info, map_info->floor, p.y, p.x);
		map[p.y][p.x] = '0';
		map[p.y + 1][p.x] = 'P';
	}
	else if (map[p.y + 1][p.x] == 'E' && count_coin(map_info->map) == 0)
	{
		draw_img(map_info, map_info->ply_front, p.y + 1, p.x);
		draw_img(map_info, map_info->floor, p.y, p.x);
		ft_clean(map_info);
		printf("%d\n", ++(*mv));
		ft_printf("Congratulations you have collected all coins!");
		exit(0);
	}
}

int	key_hook(int keysym, t_map_info *map_info)
{
	static int	mv;

	if (keysym == XK_Escape)
	{
		ft_clean(map_info);
		exit(0);
	}
	if (keysym == XK_a)
		ft_xk_a(map_info, &mv);
	else if (keysym == XK_d)
		ft_xk_d(map_info, &mv);
	else if (keysym == XK_w)
		ft_xk_w(map_info, &mv);
	else if (keysym == XK_s)
		ft_xk_s(map_info, &mv);
	return (0);
}
