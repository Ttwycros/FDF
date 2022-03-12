/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:18:52 by ttwycros          #+#    #+#             */
/*   Updated: 2021/11/21 17:18:52 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_line(char *full_buff)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!full_buff[i])
		return (0);
	while (full_buff[i] && full_buff[i] != '\n')
		i++;
	new_line = malloc(sizeof(char) * (i + 2));
	if (!new_line)
		return (0);
	i = 0;
	while (full_buff[i] && full_buff[i] != '\n')
	{
		new_line[i] = full_buff[i];
		i++;
	}
	if (full_buff[i] == '\n')
	{
		new_line[i] = full_buff[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

int	full_buff_terminate(char **full_buff, int i)
{
	char	*full_buff_temp;

	full_buff_temp = *full_buff;
	if (!full_buff_temp[i])
	{
		free(full_buff);
		return (1);
	}
	return (0);
}

char	*reset_full_buff(char *full_buff)
{
	char	*temp_full_buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (full_buff[i] && full_buff[i] != '\n')
		i++;
	if (!full_buff[i])
	{
		free(full_buff);
		return (0);
	}
	temp_full_buff = malloc(sizeof(char) * ((ft_strlen(full_buff) - i) + 1));
	if (!temp_full_buff)
		return (0);
	i++;
	while (full_buff[i])
		temp_full_buff[j++] = full_buff[i++];
	temp_full_buff[j] = '\0';
	free(full_buff);
	return (temp_full_buff);
}

char	*read_fd(int fd, char *full_buff)
{
	int		bytes_was_read;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	bytes_was_read = 1;
	while (ft_check_for_n(full_buff) && bytes_was_read != 0)
	{
		bytes_was_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_was_read == -1)
		{
			free(buff);
			return (0);
		}
		buff[bytes_was_read] = '\0';
		full_buff = ft_strjoin_mod(full_buff, buff);
	}
	free(buff);
	return (full_buff);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*full_buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	full_buff = read_fd(fd, full_buff);
	if (!full_buff)
		return (0);
	buff = get_line(full_buff);
	full_buff = reset_full_buff(full_buff);
	return (buff);
}
