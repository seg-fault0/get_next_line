/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:04:55 by wimam             #+#    #+#             */
/*   Updated: 2024/11/24 02:21:11 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_data(int fd, char *old)
{
	char	*tmp;
	char	*buffer;
	int		read_byte;
	char	*data;

	if (ft_new_line_check(old))
		return (old);
	if (!old)
		old = ft_init(NULL);
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	tmp[BUFFER_SIZE] = '\0';
	read_byte = 0;
	buffer = ft_init(NULL);
	while ((read_byte = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		buffer = ft_strljoin(buffer, tmp, read_byte);
		if (ft_new_line_check(tmp))
			break ;
	}
	free(tmp);
	if (read_byte <= 0 && !buffer)
	{
		free(buffer);
		return (NULL);	
	}
	data = ft_strljoin(old, buffer, ft_strlen(buffer));
	free(buffer);
	return (data);
}

char	*ft_get_line(char	*data)
{
	int		i;
	char	*line;
	
	if (*data == '\0')
		return (NULL);
	i = 0;
	while (data[i] != '\0' && data[i] != '\n')
		i++;
	line = malloc(i + 1 + 1);
	i = 0;
	while (data[i] != '\0' &&data[i] != '\n')
	{
		line[i] = data[i];
		i++;
	}
	line[i] = data[i];
	line[++i] = '\0';
	return (line);
}

char	*ft_update_data(char *text)
{
	int		trim_len;
	int		text_len;
	char	*new_text;

	text_len = ft_strlen(text);
	trim_len = 0;
	while (text[trim_len] != '\0' && text[trim_len] != '\n')
		trim_len++;
	if(trim_len == text_len)
	{
		free(text);
		return (NULL);
	}
	trim_len++;
	new_text = ft_strdup(text + trim_len);
	free(text);
	return (new_text);
}

char	*get_next_line(int fd)
{
	static	char	*data;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)	
		return (NULL);

	data = ft_get_data(fd, data);
	line = ft_get_line(data);
	data = ft_update_data(data);
	return (line);
}
