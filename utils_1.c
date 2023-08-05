/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:21:51 by yachen            #+#    #+#             */
/*   Updated: 2023/08/05 14:03:39 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	count_coin(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

int	count_str(char *argv)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = 0;
	fd = open(argv, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
		free(line);
	}
	return (i);
}

/* if fd not valid exit(1), if allocation map failed return NULL*/
char	**make_map(char **argv)
{
	int		i;
	int		fd;
	char	**map;

	i = 0;
	fd = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n: Opening file failed");
		exit(1);
	}
	map = (char **)malloc(sizeof(char *) * (count_str(argv[1]) + 1));
	if (!map)
		return (NULL);
	while (1)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			break ;
		i++;
	}
	map[i] = NULL;
	return (map);
}

/* if !map || map not rectangular || map size < size minimum
 return size = 0*/
t_point	find_map_size(char **map)
{
	t_point	size;
	int		i;
	int		x;

	size.y = 0;
	size.x = 0;
	x = 0;
	if (!map)
		return (size);
	i = 0;
	x = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != x)
			return (size);
		i++;
	}
	size.x = x - 1;
	size.y = i;
	if (size.y < 3 || size.x < 5)
	{
		size.x = 0;
		size.y = 0;
	}
	return (size);
}
