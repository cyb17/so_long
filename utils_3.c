/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:01:18 by yachen            #+#    #+#             */
/*   Updated: 2023/08/05 14:04:25 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* check if we have a valid exit */
int	check_exit(char **map, t_point size, int y, int x)
{
	if (y >= size.y - 1 || x >= size.x - 1 || y <= 0 || x <= 0
		|| map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	if (map[y][x] == 'E')
		return (1);
	map[y][x] = 'V';
	if (check_exit(map, size, y, x + 1) || check_exit(map, size, y, x - 1)
		|| check_exit(map, size, y + 1, x)
		|| check_exit(map, size, y - 1, x))
		return (1);
	return (0);
}

/* check if the map is closed by walls */
int	ft_check_wall(char **map, t_point size)
{
	int	i;

	i = 0;
	while (i < size.x)
	{
		if (map[0][i] != '1' || map[size.y - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < size.y)
	{
		if (map[i][0] != '1' || map[i][size.x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	ft_error2(char **map)
{
	free_tab(map);
	perror("Error\n: Map content is not valid");
	exit(1);
}

void	ft_error1(char **map)
{
	free_tab(map);
	perror("Error\n: Map size is not valid");
	exit(1);
}

void	ft_init(t_content *cnt)
{
	cnt->e = 0;
	cnt->p = 0;
	cnt->c = 0;
}
