/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:57:14 by yachen            #+#    #+#             */
/*   Updated: 2023/08/05 16:19:41 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check and exit(1) if map have something else than "1,0,P,E,C,\n"
void	ft_check_content(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
			&& map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != '\n')
			{
				free_tab(map);
				perror("Error\n: Map content is not valid");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

// check if map have E,P,C else exit(1)
void	check_content(char **map)
{
	t_content	cnt;
	int			i;
	int			j;

	ft_init(&cnt);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				cnt.e++;
			else if (map[i][j] == 'P')
				cnt.p++;
			else if (map[i][j] == 'C')
				cnt.c++;
			j++;
		}
		i++;
	}
	if (cnt.e != 1 || cnt.p != 1 || cnt.c < 1)
		ft_error2(map);
}

void	find_p(char **map, t_point *p)
{
	int		i;
	int		j;

	i = 0;
	p->x = 0;
	p->y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				p->y = i;
				p->x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

/* change all accessible 'C' to 'c' */
void	check_coin(char **map, t_point size, int y, int x)
{
	if (y >= size.y - 1 || x >= size.x - 1 || y <= 0 || x <= 0
		|| map[y][x] == '1' || map[y][x] == 'E' || map[y][x] == 'V'
		|| map[y][x] == 'c')
		return ;
	if (map[y][x] == 'C')
		map[y][x] = 'c';
	else
		map[y][x] = 'V';
	check_coin(map, size, y, x + 1);
	check_coin(map, size, y, x - 1);
	check_coin(map, size, y + 1, x);
	check_coin(map, size, y - 1, x);
}

/* check if all coins are accessible */
int	check_coin2(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
