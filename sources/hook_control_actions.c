/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_controls_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:00:51 by mstrantz          #+#    #+#             */
/*   Updated: 2021/08/17 10:04:19 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(int key, t_fdf *fdf)
{
	if (key == MINUS)
		fdf->camera->zoom--;
	else if (key == PLUS)
		fdf->camera->zoom++;
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	ft_create_image(fdf->map, fdf);
}

void	ft_translate_map(int key, t_fdf *fdf)
{
	if (key == UP)
		fdf->camera->y_offset -= 10;
	else if (key == DOWN)
		fdf->camera->y_offset += 10;
	else if (key == LEFT)
		fdf->camera->x_offset -= 10;
	else if (key == RIGHT)
		fdf->camera->x_offset += 10;
	ft_create_image(fdf->map, fdf);
}

void	ft_adjust_z_values(int key, t_fdf *fdf)
{
	if (key == LESS)
		fdf->camera->z_divisor -= 0.1;
	else if (key == MORE)
		fdf->camera->z_divisor += 0.1;
	if (fdf->camera->z_divisor < 0.1)
		fdf->camera->z_divisor = 0.1;
	else if (fdf->camera->z_divisor > 10)
		fdf->camera->z_divisor = 10;
	ft_create_image(fdf->map, fdf);
}

void	ft_rotate_axes(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_2)
		fdf->camera->alpha += 0.05;
	else if (key == NUM_PAD_8)
		fdf->camera->alpha -= 0.05;
	else if (key == NUM_PAD_4)
		fdf->camera->beta -= 0.05;
	else if (key == NUM_PAD_6)
		fdf->camera->beta += 0.05;
	else if (key == NUM_PAD_1)
		fdf->camera->gamma += 0.05;
	else if (key == NUM_PAD_9)
		fdf->camera->gamma -= 0.05;
	ft_create_image(fdf->map, fdf);
}

void	ft_switch_projection(int key, t_fdf *fdf)
{
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	if (key == KEY_I)
		fdf->camera->projection = ISO;
	else if (key == KEY_P)
		fdf->camera->projection = PARALLEL;
	ft_create_image(fdf->map, fdf);
}
