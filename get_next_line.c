/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:12:22 by ggevorgi          #+#    #+#             */
/*   Updated: 2024/11/24 21:30:58 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_ptr(char **str)
{
	free(*str);
	*str = NULL;
}



char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	

	return (line);
}