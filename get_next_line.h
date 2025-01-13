/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:14:42 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/01/13 17:31:52 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1000000
#endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

#include <stdio.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);
char	*ft_strchr(const char *s, int c);

#endif