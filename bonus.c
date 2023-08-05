/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:19:15 by yachen            #+#    #+#             */
/*   Updated: 2023/08/05 16:21:05 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	enmy_loop(t_map_info *map_info, t_enmy *enmy, int i, int j)
{
	draw_img(map_info, enmy->pos1, i, j);
	sleep(1);
	draw_img(map_info, enmy->pos1, i, j);
}

void	load_enmy(t_map_info *map_info)
{
	int		i;
	int		j;
	t_enmy	*enmy;
	char	**map;

	i = 0;
	map = map_info->map;
	enmy = malloc(sizeof(t_enmy *) * 2);
	if (!enmy)
		return ;
	enmy->pos1 = load_img(map_info->mlx, "./map_img/enmy1.xpm");
	enmy->pos2 = load_img(map_info->mlx, "./map_img/enmy2.xpm");
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'Y')
				enmy_loop(map_info, enmy, i, j);
			j++;
		}
		i++;
	}
}
