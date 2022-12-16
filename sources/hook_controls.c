/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 20:21:34 by mstrantz          #+#    #+#             */
/*   Updated: 2021/08/23 19:18:04 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_action_after_keypress(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == ESC)
		exit(0);
	else if (key == MINUS || key == PLUS)
		ft_zoom(key, fdf);
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
		ft_translate_map(key, fdf);
	else if (key == LESS || key == MORE)
		ft_adjust_z_values(key, fdf);
	else if (key == KEY_I || key == KEY_P)
		ft_switch_projection(key, fdf);
	else if (key == NUM_PAD_1 || key == NUM_PAD_2 || key == NUM_PAD_4
		|| key == NUM_PAD_6 || key == NUM_PAD_8 || key == NUM_PAD_9)
		ft_rotate_axes(key, fdf);
	return (0);
}

int	ft_close(void)
{
	exit(0);
}

void	ft_hook_controls(t_fdf *fdf)
{
	mlx_hook(fdf->win, 02, (1L << 0), ft_action_after_keypress, fdf);
	mlx_hook(fdf->win, 17, (1L << 17), ft_close, fdf);
}
