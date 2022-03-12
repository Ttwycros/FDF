/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:21:06 by ttwycros          #+#    #+#             */
/*   Updated: 2022/03/12 18:57:38 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(float x1, float y1, t_fdf *data)
{
	float	max;
	t_curr	*temp;

	temp = malloc(sizeof(t_curr));
	if (!temp)
		ft_error("malloc fail");
	temp->x = data->x_temp;
	temp->y = data->y_temp;
	temp->x1 = x1;
	temp->y1 = y1;
	isometric_convert(data, temp);
	temp->x_step = temp->x1 - temp->x;
	temp->y_step = temp->y1 - temp->y;
	max = maxi(ft_abs(temp->x_step), ft_abs(temp->y_step));
	temp->x_step /= max;
	temp->y_step /= max;
	while ((int)(temp->x - temp->x1) || (int)(temp->y - temp->y1))
	{
		if (temp->x < WIDTH && temp->y < HEIGHT && temp->x >= 0 && temp->y >= 0)
			my_mlx_pixel_put(data, temp->x, temp->y, data->color);
		temp->x += temp->x_step;
		temp->y += temp->y_step;
	}
	free(temp);
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	do_init_image(data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->x_temp = x;
			data->y_temp = y;
			if (x < data->width - 1)
				bresenham(x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y + 1, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->image, 0, 0);
}
