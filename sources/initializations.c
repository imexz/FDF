/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 12:00:46 by mstrantz          #+#    #+#             */
/*   Updated: 2021/08/23 19:17:30 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_init_map(void)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (map == NULL)
		ft_terminate(ERR_INIT_MAP);
	map->width = 0;
	map->height = 0;
	map->coords_arr = NULL;
	map->colors_arr = NULL;
	map->z_min = 2147483647;
	map->z_max = -2147483648;
	map->z_range = 0;
	return (map);
}

t_fdf	*ft_init_fdf(t_map *map)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (fdf == NULL)
		ft_free_and_terminate_1(ERR_INIT_FDF, map);
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		ft_free_and_terminate_4(ERR_INIT_FDF, map, fdf);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
	if (fdf->win == NULL)
		ft_free_and_terminate_4(ERR_INIT_FDF, map, fdf);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (fdf->img == NULL)
		ft_free_and_terminate_4(ERR_INIT_FDF, map, fdf);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->size_line), &(fdf->endian));
	fdf->map = map;
	return (fdf);
}

t_camera	*ft_init_cam(t_fdf *fdf, t_map *map)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (cam == NULL)
		ft_free_and_terminate_4(ERR_INIT_CAM, map, fdf);
	cam->zoom = WIDTH / fdf->map->width / 2;
	if (cam->zoom > (HEIGHT / fdf->map->height / 2))
		cam->zoom = (HEIGHT / fdf->map->height / 2);
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	cam->z_divisor = 1;
	cam->x_offset = 0;
	cam->y_offset = 0;
	return (cam);
}
