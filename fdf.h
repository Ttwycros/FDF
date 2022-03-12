/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:18:18 by ttwycros          #+#    #+#             */
/*   Updated: 2022/03/12 18:57:58 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

//# include "mlx/mlx.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

# define HEIGHT 2560 
# define WIDTH 1440

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	double	angle_x;
	double	angle_y;
	double	rotation;
	double	rotation_x;
	double	rotation_y;
	float	x_temp;
	float	y_temp;
	int		flag_3d;

	void	*mlx_ptr;
	void	*win_ptr;

	void	*image;
	char	*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_fdf;

typedef struct s_curr
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	float	x_step;
	float	y_step;
}	t_curr;

void	read_file(char *file_name, t_fdf *data, int i, int fd);
void	draw(t_fdf *data);
int		key_hook(int key, t_fdf *data);
int		close_window(int zero);
int		mouse_hook(int key, int x, int y, t_fdf *data);
void	isometric_convert(t_fdf *data, t_curr	*temp);
float	maxi(float a, float b);
float	ft_abs(float a);
void	do_init_image(t_fdf *data);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
int		free_data_protected(t_fdf *data);
int		free_global(t_fdf *data, int *fd, char **line);
void	ft_error(char *mess);

#endif
