/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:18:16 by ttwycros          #+#    #+#             */
/*   Updated: 2022/03/12 19:01:02 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			height++;
			free(line);
		}
		else
			break ;
	}
	close(fd);
	return (height);
}

int	get_width_from_line(char *line)
{
	int		width;
	char	**nums;

	nums = ft_split(line, ' ');
	width = 0;
	while (nums[width])
	{
		free(nums[width]);
		width++;
	}
	free(nums);
	return (width);
}

int	get_width(char *file_name)
{
	int		width;
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("Invalid map");
	line = get_next_line(fd);
	width = get_width_from_line(line);
	if (line)
		free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	if (!nums)
	{
		ft_error("Invalid map");
	}
	i = -1;
	while (nums[++i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
	}
	free(nums);
}

void	read_file(char *file_name, t_fdf *data, int i, int fd)
{
	char	*line;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (!data->z_matrix)
		ft_error("Malloc error");
	while (++i <= data->height)
	{
		data->z_matrix[i] = (int *) malloc(sizeof(int) * (data->width + 1));
		if (!data->z_matrix[i])
			ft_error("Malloc error");
	}
	i = -1;
	while (++i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->z_matrix[i], line);
		free(line);
		line = NULL;
	}
}
