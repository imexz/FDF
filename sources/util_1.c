/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:37:51 by mstrantz          #+#    #+#             */
/*   Updated: 2021/08/23 19:17:53 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *s, char c)
{
	int		found;
	size_t	num_str;
	int		i;

	found = 0;
	num_str = 0;
	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			found = 0;
		else if (found == 0)
		{
			num_str++;
			found = 1;
		}
		i++;
	}
	return (num_str);
}

void	ft_terminate(char *s)
{
	if (errno == 0)
	{
		ft_putstr_fd(s, 2);
		ft_putchar_fd('\n', 2);
	}
	else
		perror(s);
	exit(EXIT_FAILURE);
}

void	ft_free_and_terminate_1(char *s, t_map *map)
{
	if (map->coords_arr)
		free (map->coords_arr);
	if (map->colors_arr)
		free (map->colors_arr);
	free (map);
	ft_terminate(s);
}
