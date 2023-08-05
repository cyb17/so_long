/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:37:55 by yachen            #+#    #+#             */
/*   Updated: 2023/08/05 16:17:16 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*load_img(void *mlx, char *path)
{
	t_data	*img;

	if (!mlx)
		return (NULL);
	img = malloc(sizeof(t_data));
	if (!img)
		return (NULL);
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	img->adr = mlx_get_data_addr(img->img, &img->bpp, &img->l, &img->edn);
	return (img);
}

t_map_info	*ft_clean(t_map_info *map_info)
{
	mlx_destroy_image(map_info->mlx, map_info->wall->img);
	mlx_destroy_image(map_info->mlx, map_info->ply_back->img);
	mlx_destroy_image(map_info->mlx, map_info->ply_front->img);
	mlx_destroy_image(map_info->mlx, map_info->ply_left->img);
	mlx_destroy_image(map_info->mlx, map_info->ply_right->img);
	mlx_destroy_image(map_info->mlx, map_info->coin->img);
	mlx_destroy_image(map_info->mlx, map_info->floor->img);
	mlx_destroy_image(map_info->mlx, map_info->exit->img);
	free(map_info->wall);
	free(map_info->ply_back);
	free(map_info->ply_front);
	free(map_info->ply_left);
	free(map_info->ply_right);
	free(map_info->coin);
	free(map_info->floor);
	free(map_info->exit);
	mlx_destroy_window(map_info->mlx, map_info->mlx_w);
	mlx_destroy_display(map_info->mlx);
	free(map_info->mlx);
	free_tab(map_info->map);
	free(map_info);
	return (NULL);
}

void	draw_img(t_map_info *map_info, t_data *img, int i, int j)
{
	int	y;
	int	x;

	y = TS * i;
	x = TS * j;
	mlx_put_image_to_window(map_info->mlx, map_info->mlx_w, img->img, x, y);
}

void	load_map(t_map_info *map_info)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	tmp = map_info->map;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] != '\n')
				draw_img(map_info, map_info->floor, i, j);
			if (tmp[i][j] == '1')
				draw_img(map_info, map_info->wall, i, j);
			else if (tmp[i][j] == 'C')
				draw_img(map_info, map_info->coin, i, j);
			else if (tmp[i][j] == 'P')
				draw_img(map_info, map_info->ply_back, i, j);
			else if (tmp[i][j] == 'E')
				draw_img(map_info, map_info->exit, i, j);
			j++;
		}
		i++;
	}
}
