/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:54:11 by yachen            #+#    #+#             */
/*   Updated: 2023/08/05 14:01:40 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char**argv)
{
	t_map_info	*map_info;

	if (argc == 2 && argv[1] && argv[1][0] != '\0')
	{
		map_parsing(argv);
		map_info = map_init(argv);
		if (!map_info)
		{
			perror("Error\n : initialization of map failed");
			exit(1);
		}
		map_display(map_info);
	}
	return (0);
}
