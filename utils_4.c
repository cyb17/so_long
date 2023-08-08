/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:37:55 by yachen            #+#    #+#             */
/*   Updated: 2023/08/08 15:57:48 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_name(char **argv)
{
	size_t	i;

	i = ft_strlen(argv[1]);
	if (argv[1][i - 1] == 'r' && argv[1][i - 2] == 'e'
		&& argv[1][i - 3] == 'b' && argv[1][i - 4] == '.')
		return (1);
	return (0);
}

t_data	*load_img(void *mlx, char *path)
{
	t_data	*img;

	if (!mlx)
		return (NULL);
	img = (t_data *)malloc(sizeof(t_data));
	if (!img)
		return (NULL);
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (img->img == NULL)
	{
		free(img);
		return (NULL);
	}
	return (img);
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
