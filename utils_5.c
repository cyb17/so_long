/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:39:13 by yachen            #+#    #+#             */
/*   Updated: 2023/08/08 16:01:09 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	ft_clean1(t_map_info *map_info)
{
	if (map_info->wall)
		mlx_destroy_image(map_info->mlx, map_info->wall->img);
	if (map_info->ply_back)
		mlx_destroy_image(map_info->mlx, map_info->ply_back->img);
	if (map_info->ply_front)
		mlx_destroy_image(map_info->mlx, map_info->ply_front->img);
	if (map_info->ply_left)
		mlx_destroy_image(map_info->mlx, map_info->ply_left->img);
	if (map_info->ply_right)
		mlx_destroy_image(map_info->mlx, map_info->ply_right->img);
	if (map_info->coin)
		mlx_destroy_image(map_info->mlx, map_info->coin->img);
	if (map_info->floor)
		mlx_destroy_image(map_info->mlx, map_info->floor->img);
	if (map_info->exit)
		mlx_destroy_image(map_info->mlx, map_info->exit->img);
}

void	ft_clean2(t_map_info *map_info)
{
	if (map_info->wall)
		free(map_info->wall);
	if (map_info->ply_back)
		free(map_info->ply_back);
	if (map_info->ply_front)
		free(map_info->ply_front);
	if (map_info->ply_left)
		free(map_info->ply_left);
	if (map_info->ply_right)
		free(map_info->ply_right);
	if (map_info->coin)
		free(map_info->coin);
	if (map_info->floor)
		free(map_info->floor);
	if (map_info->exit)
		free(map_info->exit);
}

t_map_info	*ft_clean(t_map_info *map_info)
{
	ft_clean1(map_info);
	ft_clean2(map_info);
	if (map_info->mlx_w)
		mlx_destroy_window(map_info->mlx, map_info->mlx_w);
	if (map_info->mlx)
		mlx_destroy_display(map_info->mlx);
	if (map_info->mlx)
		free(map_info->mlx);
	if (map_info->map)
		free_tab(map_info->map);
	if (map_info)
		free(map_info);
	return (NULL);
}
