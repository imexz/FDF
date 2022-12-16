/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:27:25 by mstrantz          #+#    #+#             */
/*   Updated: 2021/08/23 19:17:48 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	int	i;

	if (x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

int	ft_get_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	ft_get_index(int x, int y, int width)
{
	return (y * width + x);
}

t_point	new_point(int x, int y, t_map *map)
{
	t_point	p;
	int		i;

	i = ft_get_index(x, y, map->width);
	p.x = x;
	p.y = y;
	p.z = map->coords_arr[i];
	if (p.z > 0 && map->colors_arr[i] == -1)
		p.color = 0xF3AF3D;
	else if (map->colors_arr[i] == -1)
		p.color = 0x9A1F6A;
	else
		p.color = map->colors_arr[i];
	return (p);
}

void	ft_create_background(t_fdf *fdf)
{
	int	*image;
	int	i;

	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		image[i] = 0x000000;
		i++;
	}
}
