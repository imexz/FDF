/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:25:25 by mstrantz          #+#    #+#             */
/*   Updated: 2021/08/23 19:17:45 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso(int *x, int *y, int z)
{
	int	old_x;
	int	old_y;

	old_x = *x;
	old_y = *y;
	*x = (old_x - old_y) * cos(0.523599);
	*y = -z + (old_x + old_y) * sin(0.523599);
}

static void	rotate_x(int *y, int *z, double alpha)
{
	int	old_y;

	old_y = *y;
	*y = old_y * cos(alpha) + *z * sin(alpha);
	*z = -old_y * sin(alpha) + *z * cos(alpha);
}

static void	rotate_y(int *x, int *z, double beta)
{
	int	old_x;

	old_x = *x;
	*x = old_x * cos(beta) + *z * sin(beta);
	*z = -old_x * sin(beta) + *z * cos(beta);
}

static void	rotate_z(int *x, int *y, double gamma)
{
	int	old_x;
	int	old_y;

	old_x = *x;
	old_y = *y;
	*x = old_x * cos(gamma) - old_y * sin(gamma);
	*y = old_x * sin(gamma) + old_y * cos(gamma);
}

t_point	project(t_point p, t_fdf *fdf)
{
	p.x *= fdf->camera->zoom;
	p.y *= fdf->camera->zoom;
	p.z *= fdf->camera->zoom / fdf->camera->z_divisor;
	p.x -= (fdf->map->width * fdf->camera->zoom) / 2;
	p.y -= (fdf->map->height * fdf->camera->zoom) / 2;
	rotate_x(&p.y, &p.z, fdf->camera->alpha);
	rotate_y(&p.x, &p.z, fdf->camera->beta);
	rotate_z(&p.x, &p.y, fdf->camera->gamma);
	if (fdf->camera->projection == 0)
		iso(&p.x, &p.y, p.z);
	p.x += WIDTH / 2 + fdf->camera->x_offset;
	p.y += (HEIGHT + fdf->map->height * fdf->camera->zoom) / 2
		+ fdf->camera->y_offset;
	return (p);
}
