/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:43:25 by ttwycros          #+#    #+#             */
/*   Updated: 2022/03/12 19:01:08 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_global(t_fdf *data, int *fd, char **line)
{
	free_data_protected(data);
	free(*line);
	close(*fd);
	return (EXIT_FAILURE);
}

int	free_data_protected(t_fdf *data)
{
	int	i;

	i = 0;
	while (data->z_matrix[i])
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
	free(data);
	return (EXIT_FAILURE);
}
