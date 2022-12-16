/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 14:21:39 by mstrantz          #+#    #+#             */
/*   Updated: 2021/08/23 19:17:25 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_map		*map;
	t_fdf		*fdf;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			ft_terminate(ERR_FILE);
		map = ft_init_map();
		ft_read_map_for_width_and_height(fd, map);
		if (map->width == 0)
			ft_free_and_terminate_1(ERR_MAP, map);
		ft_read_map_for_values(map, argv[1]);
		fdf = ft_init_fdf(map);
		fdf->camera = ft_init_cam(fdf, map);
		ft_create_image(map, fdf);
		ft_hook_controls(fdf);
		mlx_loop(fdf->mlx);
	}
	ft_terminate(ERR_ARGUMENT);
	return (0);
}
