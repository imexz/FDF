/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:56:13 by mstrantz          #+#    #+#             */
/*   Updated: 2021/08/23 19:17:42 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_line_algo_2(t_line_algo *line_algo)
{
	if (line_algo->delta.x > line_algo->delta.y)
	{
		line_algo->pd.x = line_algo->sign.x;
		line_algo->pd.y = 0;
		line_algo->dd.x = line_algo->sign.x;
		line_algo->dd.y = line_algo->sign.y;
		line_algo->dld = line_algo->delta.y;
		line_algo->dfd = line_algo->delta.x;
	}
	else
	{
		line_algo->pd.x = 0;
		line_algo->pd.y = line_algo->sign.y;
		line_algo->dd.x = line_algo->sign.x;
		line_algo->dd.y = line_algo->sign.y;
		line_algo->dld = line_algo->delta.x;
		line_algo->dfd = line_algo->delta.y;
	}
}

static void	ft_init_line_algo_1(t_line_algo *line_algo, t_point p0, t_point p1)
{
	line_algo->delta.x = ft_get_abs(p1.x - p0.x);
	line_algo->delta.y = ft_get_abs(p1.y - p0.y);
	if (p0.x < p1.x)
		line_algo->sign.x = 1;
	else
		line_algo->sign.x = -1;
	if (p0.y < p1.y)
		line_algo->sign.y = 1;
	else
		line_algo->sign.y = -1;
	ft_init_line_algo_2(line_algo);
	line_algo->cur.x = p0.x;
	line_algo->cur.y = p0.y;
	line_algo->err = line_algo->dfd / 2;
}

static void	ft_create_line(t_point p0, t_point p1, t_fdf *fdf, t_map *map)
{
	t_line_algo	*line_algo;

	line_algo = malloc(sizeof(t_line_algo));
	if (line_algo == NULL)
		ft_free_and_terminate_4(ERR_DRAWING, map, fdf);
	ft_init_line_algo_1(line_algo, p0, p1);
	put_pixel(fdf, line_algo->cur.x, line_algo->cur.y, p0.color);
	line_algo->t = 0;
	while (++line_algo->t < line_algo->dfd)
	{
		line_algo->err -= line_algo->dld;
		if (line_algo->err < 0)
		{
			line_algo->err += line_algo->dfd;
			line_algo->cur.x += line_algo->dd.x;
			line_algo->cur.y += line_algo->dd.y;
		}
		else
		{
			line_algo->cur.x += line_algo->pd.x;
			line_algo->cur.y += line_algo->pd.y;
		}
		put_pixel(fdf, line_algo->cur.x, line_algo->cur.y, p0.color);
	}
	free (line_algo);
}

static void	ft_create_image_helper(t_map *map, t_fdf *fdf, int x, int y)
{
	t_point	p0;
	t_point	p1;

	if (x < (map->width - 1))
	{
		p0 = new_point(x, y, map);
		p1 = new_point(x + 1, y, map);
		ft_create_line(project(p0, fdf), project(p1, fdf), fdf, map);
	}
	if (y < (map->height - 1))
	{
		p0 = new_point(x, y, map);
		p1 = new_point(x, y + 1, map);
		ft_create_line(project(p0, fdf), project(p1, fdf), fdf, map);
	}
}

void	ft_create_image(t_map *map, t_fdf *fdf)
{
	int		x;
	int		y;

	ft_create_background(fdf);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_create_image_helper(map, fdf, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
