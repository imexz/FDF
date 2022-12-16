/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 14:21:35 by mstrantz          #+#    #+#             */
/*   Updated: 2021/08/23 19:17:34 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_get_coord_parts(char **coords, t_map *map)
{
	static int	i = 0;
	int			j;
	char		**parts;

	j = 0;
	while (coords[j])
	{
		parts = ft_split(coords[j], ',');
		if (parts == NULL)
			ft_free_and_terminate_2(ERR_ARRAY, map, coords);
		ft_check_parts(parts, coords, map);
		map->coords_arr[i] = ft_atoi(parts[0]);
		if (parts[1])
			map->colors_arr[i] = ft_atoi_base(parts[1], 16);
		else
			map->colors_arr[i] = -1;
		if (map->coords_arr[i] > map->z_max)
			map->z_max = map->coords_arr[i];
		if (map->coords_arr[i] < map->z_min)
			map->z_min = map->coords_arr[i];
		j++;
		i++;
		free_arr(parts);
	}
}

void	ft_get_coords(t_map *map, char *line)
{
	char	**coords;

	coords = ft_split(line, ' ');
	if (coords == NULL)
		ft_free_and_terminate_1(ERR_ARRAY, map);
	ft_get_coord_parts(coords, map);
	free_arr(coords);
	map->z_range = map->z_max - map->z_min;
}

void	ft_read_map_for_values(t_map *map, char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_terminate(ERR_FILE);
	map->coords_arr = malloc(sizeof(int) * map->height * map->width);
	map->colors_arr = malloc(sizeof(int) * map->height * map->width);
	if (map->coords_arr == NULL || map->colors_arr == NULL)
		ft_free_and_terminate_1(ERR_ARRAY, map);
	i = map->height;
	while (i > 0)
	{
		line = get_next_line(fd);
		ft_get_coords(map, line);
		i--;
		free (line);
	}
	close (fd);
}

void	ft_read_map_for_width_and_height(int fd, t_map *map)
{
	char	*line;
	int		width;

	line = get_next_line(fd);
	map->width = get_width(line, ' ');
	if (line != NULL)
		map->height++;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
		{
			width = get_width(line, ' ');
			if (map->width != width)
				ft_terminate(ERR_MAP);
			map->height++;
		}
	}
	free(line);
	close(fd);
}
