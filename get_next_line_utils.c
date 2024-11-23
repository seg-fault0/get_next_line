/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:06:44 by wimam             #+#    #+#             */
/*   Updated: 2024/11/23 06:04:18 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int 	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

int		ft_strlen_to_new_line(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (len);
	while(str[len] != '\n' && str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	if (!s1)
		return (s2);
	buffer = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!buffer)
		return (NULL);
	while (s1[i] != '\0')
	{
		buffer[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		buffer[i + j] = s2[j];
		j++;
	}
	buffer[i + j] = '\0';
	if (s1)
		free(s1);
	return (buffer);
}

int		ft_new_line_check(const char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if(*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len])
		len++;
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

