/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:18:13 by ttwycros          #+#    #+#             */
/*   Updated: 2022/03/12 19:00:42 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	data_init(t_fdf *data)
{
	data->zoom = 20;
	data->angle_x = 0.7;
	data->angle_y = 0.7;
	data->rotation = 0.7;
	data->rotation_x = 0.7;
	data->rotation_y = 0.7;
	data->width = 0;
	data->shift_x = 450;
	data->shift_y = 250;
	data->flag_3d = 0;
}

int	main(int argc, char **agrv)
{
	t_fdf	*data;
	int		fd;

	if (argc != 2)
	{
		ft_putendl_fd("Invalid arguments", 2);
		return (EXIT_FAILURE);
	}
	data = malloc(sizeof(t_fdf));
	if (!data)
		return (EXIT_FAILURE);
	data_init(data);
	fd = open(agrv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Can not open the file");
	read_file(agrv[1], data, -1, fd);
	close(fd);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
	draw(data);
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_mouse_hook(data->win_ptr, mouse_hook, data);
	mlx_hook(data->win_ptr, 17, 0, &close_window, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
