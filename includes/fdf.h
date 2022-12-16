/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrantz <mstrantz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:58:39 by mstrantz          #+#    #+#             */
/*   Updated: 2021/08/23 19:16:24 by mstrantz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <errno.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "stdlib.h"
# include "math.h"
# include "stdio.h"

# define HEIGHT				1080
# define WIDTH				1920

# define ESC				53
# define PLUS				24
# define MINUS				27
# define LEFT				123
# define RIGHT				124
# define UP					126
# define DOWN				125
# define LESS				43
# define MORE				47
# define KEY_I				34
# define KEY_P				35
# define NUM_PAD_2			84
# define NUM_PAD_8			91
# define NUM_PAD_4			86
# define NUM_PAD_6			88
# define NUM_PAD_1			83
# define NUM_PAD_9			92

# define ERR_ARGUMENT		"Usage: ./fdf <MAP_FILE>"
# define ERR_FILE			"File: Wrong <MAP_FILE>"
# define ERR_INIT_MAP		"Map initialization error"
# define ERR_MAP			"File: Error in map"
# define ERR_MAP_READING	"Reading error"
# define ERR_ARRAY			"Array allocation error"
# define ERR_INIT_FDF		"Fdf initialization error"
# define ERR_INIT_CAM		"Camera initialization error"
# define ERR_DRAWING		"Allocation error during drawing"

typedef enum e_projection
{
	ISO,
	PARALLEL
}			t_projection;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef struct s_line_algo
{
	t_point			delta;
	t_point			cur;
	t_point			sign;
	t_point			pd;
	t_point			dd;
	int				dld;
	int				dfd;
	int				err;
	int				t;
}					t_line_algo;

typedef struct s_camera
{
	t_projection	projection;
	int				zoom;
	double			alpha;
	double			beta;
	double			gamma;
	float			z_divisor;
	int				x_offset;
	int				y_offset;
}					t_camera;

typedef struct s_map
{
	int				width;
	int				height;
	int				*coords_arr;
	int				*colors_arr;
	int				z_min;
	int				z_max;
	int				z_range;
}					t_map;

typedef struct s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	t_camera		*camera;
	t_map			*map;
}					t_fdf;

void		ft_terminate(char *s);
t_map		*ft_init_map(void);
void		ft_read_map_for_width_and_height(int fd, t_map *map);
void		ft_read_map_for_values(t_map *map, char *file);
t_fdf		*ft_init_fdf(t_map *map);
t_camera	*ft_init_cam(t_fdf *fdf, t_map *map);
void		ft_create_image(t_map *map, t_fdf *fdf);
void		ft_hook_controls(t_fdf *fdf);
void		ft_zoom(int key, t_fdf *fdf);
void		ft_translate_map(int key, t_fdf *fdf);
void		ft_adjust_z_values(int key, t_fdf *fdf);
void		ft_rotate_axes(int key, t_fdf *fdf);
void		ft_switch_projection(int key, t_fdf *fdf);
void		ft_check_parts(char **parts, char **coords, t_map *map);
void		ft_create_background(t_fdf *fdf);
t_point		new_point(int x, int y, t_map *map);
t_point		project(t_point p, t_fdf *fdf);
int			get_width(char *s, char c);
void		put_pixel(t_fdf *fdf, int x, int y, int color);
int			ft_get_abs(int num);
void		free_arr(char **arr);
void		ft_free_and_terminate_1(char *s, t_map *map);
void		ft_free_and_terminate_2(char *s, t_map *map, char **coords);
void		ft_free_and_terminate_3(char *s, t_map *map,
				char **coords, char **parts);
void		ft_free_and_terminate_4(char *s, t_map *map, t_fdf *fdf);

#endif
