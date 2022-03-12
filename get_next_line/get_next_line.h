/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:20:11 by ttwycros          #+#    #+#             */
/*   Updated: 2021/11/21 17:20:11 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);

int		ft_check_for_n(char	*src);
size_t	ft_strlen(const char	*s);
char	*ft_strjoin_mod(char *s1, char const *s2);
char	*read_fd(int fd, char *full_buff);
char	*get_line(char *str);
char	*reset_full_buff(char *full_buff);

#endif