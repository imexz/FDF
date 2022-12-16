/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:59:08 by mstrantz          #+#    #+#             */
/*   Updated: 2021/08/23 19:17:38 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_check_parts(char **parts, char **coords, t_map *map)
{
	int	check;

	check = ft_check_str_for_number(parts[0], 10);
	if (!check)
		ft_free_and_terminate_3(ERR_MAP_READING, map, coords, parts);
	if (parts[1])
		check = ft_check_str_for_number(parts[1], 16);
	if (!check)
		ft_free_and_terminate_3(ERR_MAP_READING, map, coords, parts);
}
