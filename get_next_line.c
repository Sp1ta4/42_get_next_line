/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 16:12:22 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/01/13 18:44:02 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_ptr(char **str)
{
	free(*str);
	*str = NULL;
}
int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

ssize_t	ft_read_line(int fd, char **buffer)
{
    char    *temp;
    ssize_t bytes_read;

	temp = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
    bytes_read = read(fd, temp, BUFFER_SIZE);
    if (bytes_read > 0)
    {
        temp[bytes_read] = '\0';
        char *new_buffer = ft_strjoin(*buffer, temp);                          
        free_ptr(buffer);
        *buffer = new_buffer;
    }
	free(temp);
    return (bytes_read);
}


char *extract_line(char **buffer, char *newline_pos)
{
    char *line;
    char *temp;

    line = ft_substr(*buffer, 0, newline_pos - *buffer + 1);
    if (!line)
		return (NULL);
	temp = ft_strdup(newline_pos + 1);
	if (!temp)
		return (NULL);
    free_ptr(buffer);
    *buffer = temp;
    return (line);
}


char *get_next_line(int fd)
{
    static char *buffer;
    char *line;
    char *newline_pos;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!buffer && !(buffer = ft_strdup("")))
        return (NULL);
    while (1)
    {
        if ((newline_pos = ft_strchr(buffer, '\n')))
            return (extract_line(&buffer, newline_pos));
        if (ft_read_line(fd, &buffer) <= 0)
            break;
    }
    if (buffer && *buffer)
    {
        line = ft_strdup(buffer);
        free_ptr(&buffer);
        return (line);
    }
    system("leaks get_next_line");
    return (NULL);
}

// int main(int argc, char **argv)
// {
//     int fd;
//     char *line;

//     if (argc != 2)
//     {
//         printf("Usage: %s <filename>\n", argv[0]);
//         return (1);
//     }
//     fd = open(argv[1], O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Error opening file");
//         return (1);
//     }
//     while ((line = get_next_line(fd)))
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd);
//     return (0);
// }