/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:34:35 by yachen            #+#    #+#             */
/*   Updated: 2023/08/05 16:18:44 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouse_hook(t_map_info *map_info)
{
	ft_clean(map_info);
	exit(0);
}

void	map_display(t_map_info *map_info)
{
	load_map(map_info);
	mlx_key_hook(map_info->mlx_w, key_hook, map_info);
	mlx_hook(map_info->mlx_w, 17, 0L, mouse_hook, map_info);
	mlx_loop(map_info->mlx);
}
