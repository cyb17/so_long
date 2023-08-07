/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:26:19 by yachen            #+#    #+#             */
/*   Updated: 2023/08/07 15:54:44 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_parsing(char **argv)
{
	char	**map;
	char	**map_copie;
	t_point	size;
	t_point	begin;

	map = make_map(argv);
	size = find_map_size(map);
	if (size.x == 0 || size.y == 0)
		ft_error1(map);
	ft_check_content(map);
	check_content(map);
	find_p(map, &begin);
	map_copie = make_map(argv);
	check_coin(map_copie, size, begin.y, begin.x);
	if (check_exit(map, size, begin.y, begin.x) == 0
		|| ft_check_wall(map, size) == 0 || check_coin2(map_copie) == 0)
	{
		free_tab(map_copie);
		ft_error2(map);
	}
	free_tab(map_copie);
	free_tab(map);
}
