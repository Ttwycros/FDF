/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:23:28 by ttwycros          #+#    #+#             */
/*   Updated: 2022/03/12 18:58:16 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	just_say_yes_or_no(int key)
{
	if (key == 123 || key == 124
		|| key == 125 || key == 126
		|| key == 20 || key == 19
		|| key == 12 || key == 14)
		return (1);
	return (0);
}

void static	projection_type(int key, t_fdf *data)
{
	if (key == 20)
		data->flag_3d = 1;
	if (key == 19)
		data->flag_3d = 0;
}

int	key_hook(int key, t_fdf *data)
{
	projection_type(key, data);
	if (key == 126)
		data->shift_y -= 30;
	if (key == 125)
		data->shift_y += 30;
	if (key == 123)
		data->shift_x -= 30;
	if (key == 124)
		data->shift_x += 30;
	if (key == 53)
		close_window(0);
	if (key == 12)
		data->rotation += 0.05;
	if (key == 14)
		data->rotation -= 0.05;
	if (just_say_yes_or_no(key))
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw(data);
	}
	return (0);
}

int	close_window(int zero)
{
	(void) zero;
	exit(EXIT_FAILURE);
}

int	mouse_hook(int key, int x, int y, t_fdf *data)
{
	(void) x;
	(void) y;
	if (key == 4)
		data->zoom += 1;
	if (key == 5)
		if (data->zoom > 3)
			data->zoom -= 1;
	if (key == 4 || key == 5)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw(data);
	}
	return (0);
}
