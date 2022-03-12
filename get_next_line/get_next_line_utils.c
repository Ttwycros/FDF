/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:19:24 by ttwycros          #+#    #+#             */
/*   Updated: 2021/12/03 23:51:43 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char	*s)
{
	size_t		counter;
	const char	*str_copy;

	counter = 0;
	str_copy = s;
	while (*(str_copy + counter))
		counter++;
	return (counter);
}

char	*ft_strjoin_mod(char *s1, char const *s2)
{
	char	*temp;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!temp)
		return (0);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		temp[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		temp[i++] = s2[j++];
	temp[i] = '\0';
	free(s1);
	return (temp);
}

int	ft_check_for_n(char	*src)
{
	int	i;

	i = 0;
	if (!src)
		return (1);
	while (src[i])
	{
		if (src[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}
