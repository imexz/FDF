/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 15:19:06 by mstrantz          #+#    #+#             */
/*   Updated: 2021/08/23 19:17:57 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_and_terminate_2(char *s, t_map *map, char **coords)
{
	free_arr(coords);
	free (map->coords_arr);
	free (map->colors_arr);
	free (map);
	ft_terminate(s);
}

void	ft_free_and_terminate_3(char *s, t_map *map,
	char **coords, char **parts)
{
	free_arr(parts);
	free_arr(coords);
	free (map->coords_arr);
	free (map->colors_arr);
	free (map);
	ft_terminate(s);
}

void	ft_free_and_terminate_4(char *s, t_map *map, t_fdf *fdf)
{
	if (fdf->mlx)
		free (fdf->mlx);
	if (fdf->win)
		free (fdf->win);
	if (fdf->img)
		free (fdf->img);
	if (fdf->camera)
		free (fdf->camera);
	free (fdf);
	free (map->coords_arr);
	free (map->colors_arr);
	free (map);
	ft_terminate(s);
}
