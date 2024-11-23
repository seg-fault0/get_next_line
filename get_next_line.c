/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:04:55 by wimam             #+#    #+#             */
/*   Updated: 2024/11/23 06:45:48 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(int fd)
{
	char	*tmp;
	char	*buffer;
	
	buffer = NULL;
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while(read(fd, tmp, BUFFER_SIZE))
	{
		tmp[BUFFER_SIZE] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (ft_new_line_check(tmp))
			break ;
	}
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*line;
	
	if (!buffer)
		return (NULL);
	line = malloc(ft_strlen_to_new_line(buffer) + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = buffer[i];
	line[++i] = '\0';
	return (line);
}

char	*ft_update_buffer(char *buffer)
{
	char	*new_buffer;
	int		len;
	
	len = ft_strlen_to_new_line(buffer);
	new_buffer = ft_strdup(&buffer[len + 1]);
	if (buffer)
		free (buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char		*line;
	
	if (ft_new_line_check(buffer))
	{
		line = ft_get_line(buffer);
		buffer = ft_update_buffer(buffer);
	}
	else
	{
		buffer = ft_read(fd);
		line = ft_get_line(buffer);
		buffer = ft_update_buffer(buffer);
	}
	return (line);
}